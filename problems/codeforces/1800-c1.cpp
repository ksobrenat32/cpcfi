// Problem link:
// https://codeforces.com/contest/1800/problem/C1

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long n; cin >> n;
    queue<long long> s;
    priority_queue<long long> bonus;
    long long r,army=0;

    FO(i,n){
        cin >> r;
        s.push(r);
    }

    FO(i,n){
        if(s.front() == 0){
            if(! bonus.empty()){
                army += bonus.top();
                bonus.pop();
            }
        } else {
            bonus.push(s.front());
        }
        s.pop();
    }

    cout << army << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
