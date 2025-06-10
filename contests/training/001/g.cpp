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
const int MAX=1e5+3;

 
ll t[2*MAX];
int n; 

ll query(int a,int b)
{
    ll res=0;
    for(a+=n,b+=n;a<=b;a/=2,b/=2)
    {
        if(a&1){
            res=max(res,t[a++]);
        }
        if(!(b&1)){
            res=max(res,t[b--]);
        }
    }
    return res;
}

void update(int pos,int val)
{
    pos+=n;
    t[pos]+=val;
    for(int i=pos/2;i;i/=2)
    {
        t[i]=max(t[2*i],t[2*i+1]);
    }
}
//ascii https://elcodigoascii.com.ar/

inline void solve()
{
    cin>>n;
    vector<vector<pair<int,int>>> qr(2*n+1);
    FO(i,n)
    {
        int gold,a,b; cin>>gold>>a>>b;
        qr[i+a].push_back({i+b,i});
        update(i,gold);
    }
    for(int i=n-1;i>=0;i--)
    {
        for(auto [b,section]:qr[i])
        {
            
            ll qry=query(i,min(b,n-1));
            update(section,qry);
        }
    }
    cout<<t[1]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(t,0,sizeof(t));
    solve();
    return 0;
}
