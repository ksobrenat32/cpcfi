#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

inline void solve(){
    int n, m;
    cin >> n >> m;

    if(n==1){
        cout << "1" << endl;
        return;
    }

    if(n==2){
        if(m%2==0){
            cout << "1 2" << endl;
        } else {
            cout << "2 1" << endl;
        }
        return;
    }

    // If m is bigger than n, we can repeat it n times, we dont really care
    if(m >= n){
        for(int i = n; i>0; i--){
            cout << i << " ";
        }
        cout << endl;    
    } 

    // If smaller, order the end
    else {
        FO(i,m){
            cout << n-i << " ";
        }
        FO(i,(n-m)){
            cout << i+1 << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
