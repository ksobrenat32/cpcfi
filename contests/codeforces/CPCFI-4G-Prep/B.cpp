#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://codeforces.com/problemset/problem/520/A

int main(){
    int n; cin >> n;
    string s; cin >> s;
    set<char> st;
    transform(s.begin(), s.end(), s.begin(), ::tolower);

    for(char& c : s){
        st.insert(c);
    }

    if(st.size() == 26){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}