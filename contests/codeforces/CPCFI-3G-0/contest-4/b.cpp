#include <bits/stdc++.h>

using namespace std;
 
int main() {

    int t;
    cin>>t;

    for(int i=0;i<t;i++){
        int n;
        cin>>n;

        vector<int> v(n+1);

        int dp[2][100010];

        for(int i=0;i<n;i++){
            cin>>v[i];
        }


        for(int i=0;i<2;i++){
            for(int j=0;j<=n;j++){
                dp[i][j] = 0;
            }    
        }

        for(int i=0;i<n;i++){
            if(i%2==0){
                dp[0][v[i]] = max(dp[0][v[i]], dp[1][v[i]]+1);

            }
            else{
                dp[1][v[i]] = max(dp[1][v[i]], dp[0][v[i]]+1);
            }
        }

        for(int i=1;i<=n;i++){
            cout<<max(dp[1][i],dp[0][i])<<" ";
        }

        cout<<endl;
    }

    return 0;
}
