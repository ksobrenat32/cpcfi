#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    string s; cin >> s;
    vector<int> v;
    int zero=0,one=0;

    if(s[0] == '+' && s[1] == '-'){
        v.push_back(0);
        zero++;
    } else if (s[0] == '-' && s[1] == '+'){
        v.push_back(1);
        one++;
    }

    for(size_t i = 2; i < s.size(); i+=2){
        if(s[i] == '+' && s[i+1] == '-'){
            if(v[v.size()-1] != 0){
                v.push_back(0);
                zero++;
                
            }
        } else if (s[i] == '-' && s[i+1] == '+'){
            if(v[v.size()-1] != 1){
                v.push_back(1);
                one++;
            }
        }
    }

    cout << min(zero,one) << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
