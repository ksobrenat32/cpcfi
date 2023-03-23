// Problem link:
// https://cses.fi/problemset/task//1755

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >> s;
    vector<int> v(26,0);
    deque<char> r;
    vector<int> alone(26,0);
    int a=0;

    for(char& c : s){
        v[int(c) - 65]++;
        if( v[int(c) - 65] % 2 == 0 ){
            alone[int(c) - 65]--;
            a--;
        } else {
            alone[int(c) - 65]++;
            a++;
        }
    }

    auto it = find(alone.begin(),alone.end(),1);
    if (it != alone.end()) 
    {
        int m;
        m = it - alone.begin();
        v[m]--;
        r.push_back(char(m+65));
    }

    if(a > 1){
        cout << "NO SOLUTION" << endl;
        return;
    } else {
        FO(i,26){
            while(v[i] > 0){
                v[i]-=2;
                r.push_back(char(i+65));
                r.push_front(char(i+65));
            }
        }
    }

    while(r.empty() == false ){
        cout << r.front();
        r.pop_front();
    }
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
