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
// https://omegaup.com/arena/ccp-2024-public/?fromLogin=#problems/Calificando-palabras

inline void solve(){
    unordered_map<char, int> values;
    values['1'] = 1;
    values['2'] = 2;
    values['3'] = 3;
    values['4'] = 4;
    values['5'] = 5;
    values['6'] = 6;
    values['7'] = 7;
    values['8'] = 8;
    values['9'] = 9;
    values['0'] = 0;
    values['a'] = 10;
    values['b'] = 11;
    values['c'] = 12;
    values['d'] = 13;
    values['e'] = 14;
    values['f'] = 15;
    values['g'] = 16;
    values['h'] = 17;
    values['i'] = 18;
    values['j'] = 19;
    values['k'] = 20;
    values['l'] = 21;
    values['m'] = 22;
    values['n'] = 23;
    values['o'] = 24;
    values['p'] = 25;
    values['q'] = 26;
    values['r'] = 27;
    values['s'] = 28;
    values['t'] = 29;
    values['u'] = 30;
    values['v'] = 31;
    values['w'] = 32;
    values['x'] = 33;
    values['y'] = 34;
    values['z'] = 35;
    values['A'] = 20;
    values['B'] = 22;
    values['C'] = 24;
    values['D'] = 26;
    values['E'] = 28;
    values['F'] = 30;
    values['G'] = 32;
    values['H'] = 34;
    values['I'] = 36;
    values['J'] = 38;
    values['K'] = 40;
    values['L'] = 42;
    values['M'] = 44;
    values['N'] = 46;
    values['O'] = 48;
    values['P'] = 50;
    values['Q'] = 52;
    values['R'] = 54;
    values['S'] = 56;
    values['T'] = 58;
    values['U'] = 60;
    values['V'] = 62;
    values['W'] = 64;
    values['X'] = 66;
    values['Y'] = 68;
    values['Z'] = 70;

    string ana;
    cin >> ana;
    int ana_value = 0;
    string carolina;
    cin >> carolina;
    int carolina_value = 0;

    FO(i, sz(ana)){
        ana_value += values[ana[i]];
    }
    FO(i, sz(carolina)){
        carolina_value += values[carolina[i]];
    }

    if(ana_value > carolina_value){
        cout << "Ana " << ana_value << endl;
    } else if(ana_value < carolina_value){
        cout << "Carolina " << carolina_value << endl;
    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
