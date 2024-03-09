#include<bits/stdc++.h>

using namespace std;

#define FO(i,b)   for(int i=0;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define lFOR(i,b) for(int i=0;i<b;i--)
#define all(x)    x.begin(),x.end()
#define tam(x)    x.size()
#define LB(arr,x)  lower_bound(all(arr),x)-(arr).begin()
#define UB(arr,x)  upper_bound(all(arr),x)-(arr).begin()
typedef long long ll;
typedef vector<int> vec;

//ascii https://elcodigoascii.com.ar/

inline void solve()
{
    long double n;
    cin>>n;
    int moves=0;
    while(n>1)
    {
        n/=2;
        moves++;
    }
    cout<<moves+1<<endl;

}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}