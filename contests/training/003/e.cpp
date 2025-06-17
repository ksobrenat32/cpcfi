#include <bits/stdc++.h>
using namespace std;

#define endl                        '\n'
#define FO(i, b)                    for (int i = 0; i < (b); i++)
typedef long long ll;

map<ll,ll> m;

ll query(ll x) {
    if (m.find(x) == m.end()){
        cout << x << endl;
        cout.flush();
        ll d;
        cin >> d;

        m[x] = d;
        return d;
    } else {
        return m[x];
    }
}

inline void solve(){
    ll n;
    cin >> n;
    
    ll cur = 1;

    for(int i = 1; i <= 29; i++){
        if (query(cur) == 0){
            cout << "! "  << cur << endl;
            return;
        }

        // test left child
        if (query(cur * 2) == 0){
            cout << "! "  << cur * 2 << endl;
            return;
        }
        // its the other child
        if(query(1) == i){
            cout << "! "  << (cur * 2) + 1 << endl;
            return;
        } 

        if(query(cur*2) < query(cur)){
            cur = cur * 2;
        } else {
            m[(cur * 2) + 1] = query(cur)-1;
            cur = (cur * 2) + 1;
        }
    }

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
