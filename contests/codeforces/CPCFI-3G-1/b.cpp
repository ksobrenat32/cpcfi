// Codeforces link:
// https://codeforces.com/group/qhNeDJ317x/contest/428227/problem/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    // Candy position
    int cx=1,cy=1;

    // Position
    int x=0,y=0;

    FO(i,n){
        // Move
        switch (s[i]) {
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
        }

        if(x == cx && y == cy){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
