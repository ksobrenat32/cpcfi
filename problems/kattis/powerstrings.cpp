// Problem link:
// https://open.kattis.com/problems/powerstrings

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(string &s){
    string cum = "";

    for(size_t i = 0; i < s.size(); i++){
        if(s[i] != cum[0]){
            cum += s[i];
        } else {
            if((s.size()%cum.size()) == 0 ){
                size_t j = 0;
                // Try to devide
                for(j = 0; j < (s.size()/cum.size()); j++){
                    if(cum != s.substr(cum.size()*j,cum.size()) ){
                        break;
                    }
                }
                if( j != (s.size()/cum.size())){
                    cum += s[i];                    
                } else {
                    cout << s.size()/cum.size() << endl;
                    return;
                }
            } else {
                cum += s[i];
            }
        }
    }

    // If nothing similar
    cout << "1" << endl;
}

int main(){
    string s;
    cin >> s;
    while(s != "."){
        solve(s);
        cin >> s;
    }
    return 0;
}
