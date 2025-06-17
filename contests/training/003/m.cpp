#include <bits/stdc++.h>

using namespace std;

#define ll long long
/*
string lcs(string &s, string &t){
    int m = s.size();
    int n = t.size();

    vector<vector<int>> dp(m+1, vector<int> (n+1,0));

    for(int i=1; i<=m; ++i){
        for(int j=1; j<=n; ++j){
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]+1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    int idx = dp[m][n];

    char lc[idx+1];
    lc[idx] = '\0';

    int i = m, j=n;
    while(i>0 and j>0){
        if(s[i-1] == t[j-1]){
            lc[idx-1] = s[i-1];
            i--;
            j--;
            idx--;
        }else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    string arns(lc);
    return arns;
}
*/

inline void solve(){
    string s; cin>>s;
    int n; cin>>n;
    vector<vector<int>> indices(26);
    for(int i=0; i<s.size();i++){
        indices[s[i]-97].push_back(i);
    }

    bool flag = true;
    for(int i=1; i<=n; ++i){
        string t; cin>>t;
        string arns = "";
        int last=-1;
        for(int j=0; j<t.size(); j++){
            if(indices[t[j]-97].empty()){
                flag = false;
                break;
            }

            auto it = upper_bound(indices[t[j]-97].begin(),indices[t[j]-97].end(),last);

            if(it == indices[t[j]-97].end()){
                flag = false;
                break;
            }
            //cout<< *it << last<<endl;
            if(*it < last) break;

            last = *it;
            arns+=t[j];
        }

        if(!flag and arns.empty()){
            //cout<<arns<<endl;
            cout<<"IMPOSSIBLE"<<endl;
        } 
        else cout<<arns<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}