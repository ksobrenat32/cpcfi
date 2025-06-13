#include<bits/stdc++.h>
 
using namespace std;
 
#define FO(i,b)   for(int i=0;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define lFOR(i,b) for(int i=1;i<=b;i++)
#define all(x)    x.begin(),x.end()
#define tam(x)    x.size()
#define LB(arr,x)  lower_bound(all(arr),x)-(arr).begin()
#define UB(arr,x)  upper_bound(all(arr),x)-(arr).begin()
#define X first 
#define Y second
 
typedef long long ll;
typedef vector<int> vec;
const ll mod=1e9+7;
const int MAX=2e5+3;

//ascii https://elcodigoascii.com.ar/

inline void solve()
{
    int n; cin>>n;
    vector<int> nm(61);
    FO(i,n){
        int a; cin>>a;
        nm[a]=1;
    }
    ll res=0;
    ll base=1;
    for(int i=1;i<=60;i++)
    {
        if(nm[i]) res+=base;
        base*=2;
    }
    cout<<res<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--)
        solve();
    return 0;
}
