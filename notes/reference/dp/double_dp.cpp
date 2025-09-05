typedef long long ll;
typedef vector<int> vec;
const ll mod=1e9+7;
const ll MAX=1e6+3;
ll dp[MAX][2];
//ascii https://elcodigoascii.com.ar/

inline void solve()
{
    int n; cin>>n;
    dp[n][0]=1;
    dp[n][1]=1;
    for(int i=n-1;i>0;i--)
    {
        dp[i][1]=4*dp[i+1][1]+dp[i+1][0];
        dp[i][0]=2*dp[i+1][0]+dp[i+1][1];
        dp[i][1]%=mod;
        dp[i][0]%=mod;
    }
    cout<<(dp[1][1]+dp[1][0])%mod<<endl;
}
