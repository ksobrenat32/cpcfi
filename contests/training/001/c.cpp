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
 
typedef unsigned long long ll;
typedef vector<int> vec;
const ll mod=1e9+7;
const int MAX=2e5+3;



//ascii https://elcodigoascii.com.ar/

inline void solve()
{
    ll n,k;
    cin>>n>>k;
    ll left,right;
    if(n%2==1){
        left=(n+1)/2;
        right=n+2;
    }
    else {
        left=(n+2)/2;
        right=n+1;
    }
    
    ll aux=(left*right)%mod;
    aux=(aux*(k+1))%mod;
    cout<<aux<<endl;
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
