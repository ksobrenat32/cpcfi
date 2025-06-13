#include <bits/stdc++.h>
using namespace std;

#define endl                        '\n'
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& v : (arr))
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end()
#define sz(x)                       (int) x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// cout << setprecision(11);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://codeforces.com/group/kpNr48xCia/contest/615822/problem/D

map<ll, ll> m;

long long divisor(long long num) {
    if (m.find(num) != m.end()) {
        return m[num];
    }
    ll orig = num;

    long long total = 1;

    for (int i = 2; (long long)i * i <= num; i++) {
        if (num % i == 0) {
            int e = 0;
            do {
                e++;
                num /= i;
            } while (num % i == 0);

            long long sum = 0, pow = 1;
            do {
                sum += pow;
                pow *= i;
            } while (e-- > 0);
            total *= sum;
        }
    }
    if (num > 1) {
        total *= (1 + num);
    }

    m[orig] = total - orig;
    return total - orig;
}

inline void solve(){
    int n;
    cin >> n;

    bool p=0, r=0, a=0;
    if(divisor(n) == n){
        p = true;
    }
    if(divisor(divisor(n)) == n){
        r = true;
    }
    if(divisor(n) > n){
        a = true;
    }

    if(!p && !r && !a){
        cout << n << " complicado" << endl;
    } else if(p){
        cout << n << " perfecto" << endl;
    } else if(r && a){
        cout << n << " romantico abundante" << endl;
    } else if(r){
        cout << n << " romantico" << endl;
    } else if(a){
        cout << n << " abundante" << endl;
    }
}

int main(){
    m[1] = 0;
    m[0] = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
