// Codeforces link:
// https://codeforces.com/group/qhNeDJ317x/contest/428227/problem/D

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long long int n;
    cin >> n;

    string s;
    cin >> s;

    string a;
    set<char> ca;

    // Build a string
    for ( char c : s ){
        if(ca.count(c) == 0){
            a += c;
            ca.insert(c);
        } else if ( ca.size() < 26 ){
            // If there are still different letters
            continue;
        }
        else {
            break;
        }
    }

    // Build b string where a stoped building
    string b = s.substr(a.size());
    set<char> cb(b.begin(), b.end());

    cout << ca.size() + cb.size() << endl;

}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
