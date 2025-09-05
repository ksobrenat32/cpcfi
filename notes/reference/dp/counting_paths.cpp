int n; cin>>n;
char grid[n][n];
int dp[n][n];

for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        cin>>grid[i][j];
        dp[i][j] = 0;
    }
}
if(grid[0][0] != '*')dp[0][0] = 1;
else dp[0][0] = 0;
for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(grid[i+1][j] == '.' and i+1 < n){
            dp[i+1][j] += dp[i][j]%MOD;
        }
        if(grid[i][j+1] == '.' and j+1 < n){
            dp[i][j+1] += dp[i][j]%MOD;
        }

        if(grid[i][j] == '*'){
            dp[i][j] = 0;
        }
    }
}
cout<<dp[n-1][n-1]%MOD<<endl;
