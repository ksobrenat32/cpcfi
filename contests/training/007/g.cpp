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
#define X                       first
#define Y                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const ll INF=1e17;
/*
   
    10^8
    
*/
inline void solve(){
    ll L; int G; cin>>L>>G;
    vector<pll> goombas(G);
    for(int i=0; i<G; i++){
        ll a; int b; cin>>a>>b;
        goombas[i]={a,b};
    }
    sort(all(goombas));
    ll t = 0;
    for(int i=0;i<G;i++){
        if(goombas[i].Y==0){
            t = max(t, goombas[i].X);
        }else{
            t = max(t, L - goombas[i].X);
        }
    }
    cout<<t<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}