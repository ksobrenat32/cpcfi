#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)                for (int i = 0; i < (b); i++)
#define FOR(i, a, b)            for (int i = (a); i < (b); i++)
#define rFOR(i, a, b)           for (int i = (a); i > (b); i--)
#define TR(v, arr)              for (auto& (v) : (arr))
#define pb                      push_back
#define mp                      make_pair
#define F                       first
#define S                       second
#define all(x)                  x.begin(), x.end()
#define sz(x)                   (int) x.size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<ll> vll;

inline void solve(){
    // number of docs
    int n; cin >> n;
    // instructions:
    /*
    '1'  — scanning. Document i is sent to the device memory and is placed on top of everything already there.
    '2'  — printing from memory. If the memory is not empty, the device prints the topmost document in memory and removes it from there. Otherwise, the device prints document i.
    '3'  — quick print. The device prints document i. 
    */
    string s; cin >> s;
    stack<int> pila;
    set<int> magia;

    FO(i,n){
        if(s[i] == '1'){
            pila.push(i+1);
        } else if(s[i] == '2') {
            if(!pila.empty()){
                pila.pop();
                magia.insert(i+1);
            }
        }
    }

    /*
    In the first line — the number k of documents that were not printed.
    In the second line — their numbers in increasing order, separated by spaces. If k=0, the second line is empty.
    */
    while(!pila.empty()){
        magia.insert(pila.top());
        pila.pop();
    }
    cout << magia.size() << endl;
    TR(x, magia){
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}

