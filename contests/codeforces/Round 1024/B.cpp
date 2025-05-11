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
// https://codeforces.com/contest/2102/problem/B

inline void solve(){
    int n; cin >> n;
    vector<int> a(n, 0);

    FO(i, n) cin >> a[i];

    // Desired median
    int desired_median = abs(a[0]);

    vector<int> abs_values;
    FO(i, n) {
        abs_values.pb(abs(a[i]));
    }

    sort(all(abs_values));

    int median_pos = (n + 1) / 2 - 1;
    int first_pos = find(abs_values.begin(), abs_values.end(), desired_median) - abs_values.begin();
    int bigger_numbers = abs_values.size() - first_pos - 1;

    // When the vector is sorted, if we change the sign of the last element, this, will move
    // all the elements to the right. So imagine we put a negative sign to the desired_median
    // It would make it the smallest element in the vector, and the rest of the elements would be
    // to the right of it. So if we have enough bigger numbers, we can make the desired_median
    // the median of the array. Because making them negative will make them smaller
    // than the desired_median.

    // So we need to check if the number of bigger numbers is equal or more than to half of the array
    // size
    if (bigger_numbers >= median_pos) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
