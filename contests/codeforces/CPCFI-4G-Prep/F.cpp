#include <bits/stdc++.h>
using namespace std;

// Problem link:
// https://codeforces.com/problemset/problem/550/A

int main(){
    string s;
    cin >> s;
    bool AB = false;
    bool BA = false;

    for(int i = 0; i < int(s.size())-1; i++){
        if( !AB && (s[i] == 'A' && s[i+1] == 'B') ){
            AB = true;
            i += 1;
            continue;
        }
        if( !BA && (s[i] == 'B' && s[i+1] == 'A') ){
            BA = true;
            i += 1;
            continue;
        }
    }

    if( AB && BA ){
        cout << "YES" << endl;
    } else {
        AB = false;
        BA = false;

        reverse(s.begin(), s.end());

        for(int i = 0; i < int(s.size())-1; i++){
            if( !AB && (s[i] == 'A' && s[i+1] == 'B') ){
                AB = true;
                i += 1;
                continue;
            }
            if( !BA && (s[i] == 'B' && s[i+1] == 'A') ){
                BA = true;
                i += 1;
                continue;
            }
        }


        if( AB && BA ){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
