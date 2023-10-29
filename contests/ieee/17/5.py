# Read n and m
n, m = map(int, input().split())

rhyming_groups = {}
rhyming_count = [0]

# Build groups
for i in range(n):
    line = input().lower().split()
    for word in line:
        rhyming_groups[word] = i + 1
    rhyming_count.append(0)

input()

res = []

for i in range(m):
    line = input().lower().split()
    word = line[-1]
    if word in rhyming_groups:
        res.append(rhyming_groups[word])
        rhyming_count[rhyming_groups[word]] += 1;
    else:
        res.append(-1)

for i in range(len(res)):
    if rhyming_count[res[i]] == 1:
        res[i] = -1

cnt = 0
letters = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'Z']

rhyming_letter = {}
for i in range(len(res)):
    if res[i] == -1:
        res[i] = 'X'
    else:
        if res[i] in rhyming_letter:
            res[i] = rhyming_letter[res[i]]
        else:
            rhyming_letter[res[i]] = letters[cnt]
            cnt += 1
            res[i] = rhyming_letter[res[i]]

for char in res:
    print(char, end='')
print()