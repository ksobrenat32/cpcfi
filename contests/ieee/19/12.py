#!/usr/bin/env python3

import sys
import shlex
import re
from collections import defaultdict

rules = {}
rule_line = sys.stdin.readline().strip()
if rule_line:
    for part in rule_line.split(','):
        key, value = part.strip().split('=')
        rules[key] = int(value)

field_id = {}
header_line = sys.stdin.readline().strip()
if header_line:
    for index, name in enumerate(header_line.split(', ')):
        field_id[name] = index

# Process log

user_data = defaultdict(lambda: defaultdict(lambda: {
    'ips': set(),
    'agents': set(),
    'sessions': set(),
    'pdf_count': 0,
    'crawl_stats': {'last_pdf': -1, 'current_seq': 0, 'max_seq': 0}
}))

pdf_regex = re.compile(r'GET /document/(\d+)\.pdf HTTP/1\.1')

while True:
    line = sys.stdin.readline()
    if not line:
        break

    line = line.strip()
    if not line:
        continue

    parts = shlex.split(line)

    status = parts[field_id['HTTP Status']]
    if status != '200':
        continue

    user_id = parts[field_id['Id']]
    if user_id == '-':
        continue

    full_date_str = parts[field_id['Date']]
    day = full_date_str[1:12] 
    ip = parts[field_id['Client IP']]
    agent = parts[field_id['User Agent']]
    session = parts[field_id['Session Cookie']]
    request = parts[field_id['Request']]

    today_stats = user_data[user_id][day]

    if ip != '-':
        today_stats['ips'].add(ip)
    if agent != '-':
        today_stats['agents'].add(agent)
    if session != '-':
        today_stats['sessions'].add(session)

    pdf_match = pdf_regex.match(request)
    if pdf_match:
        today_stats['pdf_count'] += 1
        
        pdf_num = int(pdf_match.group(1))
        crawl = today_stats['crawl_stats']
        
        if pdf_num == crawl['last_pdf'] + 1:
            crawl['current_seq'] += 1
        else:
            crawl['current_seq'] = 1
        
        crawl['last_pdf'] = pdf_num
        crawl['max_seq'] = max(crawl['max_seq'], crawl['current_seq'])

# Get all the violations
violations = []
for user_id, days_data in user_data.items():
    for day, stats in days_data.items():
        
        if 'agent' in rules and len(stats['agents']) >= rules['agent']:
            violations.append((user_id, 'agent', len(stats['agents'])))
        if 'ip' in rules and len(stats['ips']) >= rules['ip']:
            violations.append((user_id, 'ip', len(stats['ips'])))
        if 'pdf' in rules and stats['pdf_count'] >= rules['pdf']:
            violations.append((user_id, 'pdf', stats['pdf_count']))
        if 'session' in rules and len(stats['sessions']) >= rules['session']:
            violations.append((user_id, 'session', len(stats['sessions'])))
        if 'crawl' in rules and stats['crawl_stats']['max_seq'] >= rules['crawl']:
            violations.append((user_id, 'crawl', stats['crawl_stats']['max_seq']))

if not violations:
    print("N/A")
else:
    violations.sort(key=lambda x: (x[0], x[1]))
    for user_id, abuse_type, value in violations:
        print(f"{user_id} {abuse_type}={value}")
