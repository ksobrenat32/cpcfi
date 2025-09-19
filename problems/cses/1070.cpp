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

inline void solve(){
    int n; cin >> n;

    if(n <= 3 && n != 1){
        cout << "NO SOLUTION" << endl;
        return;
    }

    for(int i = 2; i <= n; i+=2){
        cout << i << " ";
    }
    for(int i = 1; i <= n; i+=2){
        cout << i << " ";
    }
    cout << endl;
    
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
