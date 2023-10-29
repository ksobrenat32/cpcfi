#include <bits/stdc++.h>
using namespace std;

#define endl                        '\n'
#define FO(i, b)                    for (int i = 0; i < (b); i++)
#define FOR(i, a, b)                for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)               for (int i = (a); i > (b); i--)
#define TR(v, arr)                  for (auto& v : (arr))
#define pb                          push_back
#define mp                          make_pair
#define F                           first
#define S                           second
#define all(x)                      x.begin(), x.end() 
#define sz(x)                       (int) x.size()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

// cout << setprecision(11);
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

// Problem link:
// https://csacademy.com/ieeextreme17/task/caesar_redux/

void shiftR(int n, string &s){
    int t;
    FO(i, sz(s)){
        if(s[i] != ' '){
            t = int(s[i]) - 97;
            t += n;
            if(t > 25){
                t -= 26;
            }
            s[i] = char(t + 97);
        }
    }
}

void shiftL(int n, string &s){
    int t;
    FO(i, sz(s)){
        if(s[i] != ' '){
            t = int(s[i]) - 97;
            t -= n;
            if( t < 0){
                t += 26;
            }
            s[i] = char(t + 97);
        }
    }
}


inline void solve(){
    int n;
    cin >> n;
    string tmp;
    cin.ignore();
    getline(cin,tmp);

    if( tmp.find(" the ") != string::npos || tmp.find(" the") == tmp.size()-4 || tmp.find("the ") == 0){
        shiftL(n, tmp);
        cout << tmp << endl;
    } else {
        shiftR(n, tmp);
        cout << tmp << endl;
    }


}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
