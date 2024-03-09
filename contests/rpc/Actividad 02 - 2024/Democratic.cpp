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
    int n,m;
    cin>>n>>m;
    int alpha[26][m];
    FO(i,26)
    {
        FO(j,m)
        {
            alpha[i][j]=0;
        }
    }
    FO(i,n)
    {
        string s;
        cin>>s;
        FO(j,m)
        {
            alpha[s[j]-97][j]++;
        }
    }  
    string res="";
    int index=0;
    FO(i,m)
    {
        int mayor=-1;
        FO(j,26)
        {
            if(alpha[j][i]>mayor)
            {
                mayor=alpha[j][i];
                index=j;
            }
        }
        res+=(char) index+97;
        //cout<<res<<" ";
    } 
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}