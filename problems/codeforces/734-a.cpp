// Problem link:
// https://codeforces.com/problemset/problem/734/A

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    long unsigned int a=0;

    for( char& c : s){
       if( c == 'A'){
        a++;
       } 
    }

    if( a > (s.size() - a)){
        cout << "Anton" << endl;
    } else if ( a < (s.size() - a) ) {
        cout << "Danik" << endl;
    } else {
        cout << "Friendship" << endl;
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
