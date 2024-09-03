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
// https://cses.fi/problemset/task/1753

// LPS for s, lps[i] could also be defined as the longest prefix which is also a proper suffix
vi computeLPS(string s){
    size_t len = 0;
    size_t M = s.size();
    vi lps(M, 0);

    size_t i = 1;
    while(i < M) {
        if( s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0){
                len = lps[len-1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Get number of occurrences of a pattern in a text using KMP
// O(N+M)
size_t KMPOccurrences(string pattern, string text){
    vi lps = computeLPS(pattern); // LPS array

    size_t M = pattern.size();
    size_t N = text.size();

    size_t i = 0; // Index for text
    size_t j = 0; // Index for pattern

    size_t cnt = 0; // Counter

    while ((N - i) >= (M - j)) {
        // Watch for the pattern
        if (pattern[j] == text[i]) {
            j++;
            i++;
        }

        // If the full match found
        if (j == M) {
            cnt++;
            j = lps[j - 1];
        }

        // Mismatch after j matches
        else if (i < N && pattern[j] != text[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    return cnt;
}

inline void solve(){
    string s1; cin>>s1;
    string s2; cin>>s2;

    size_t cnt = KMPOccurrences(s2, s1);

    cout << cnt << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
