// Time limit exceeded

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(vector<vector<long>> &memo, int &col, long &mx){
    long long n;
    cin >> n;
    bool visited=false;

    if(n == 1){
        cout << 1 << endl;
        return;
    }

    while(true){
        // If not new query only the last one
        if(visited){
            if(find(memo[col-1].begin(),memo[col-1].end(),n) != memo[col-1].end()){
                cout << col << endl;
                return;
            }
        } else {
            // If new, search in existing
            if(n <= mx){
                FO(i,col){
                    if(find(memo[i].begin(),memo[i].end(),n) != memo[i].end()){
                        cout << i+1 << endl;
                        return;
                    }
                }
            }
        }

        
        // If not found create new line
        vector<long> nw;
        nw.push_back(1);
        for(size_t i = 0; i < (memo[col-1].size()-1); i++){
            nw.push_back(memo[col-1][i] + memo[col-1][i+1]);
            mx = max(memo[col-1][i] + memo[col-1][i+1],mx);
        }
        nw.push_back(1);
        memo.push_back(nw);
        col++;
        visited=true;
    }

}

int main(){
    long T=1;
    cin>>T;
    vector<vector<long>> memo;
    int col=2;

    vector<long> l1;
    l1.push_back(1);
    memo.push_back(l1);

    vector<long> l2;
    l2.push_back(1);
    l2.push_back(1);
    memo.push_back(l2);

    long mx=1;

    FO(tc,T){
        solve(memo,col,mx);
    }
    return 0;
}