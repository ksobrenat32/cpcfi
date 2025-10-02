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

inline void solve(){
    long double ni, t; 
    cin >> ni >> t;

    multiset<long double> p, n;
    char c;
    long double x;

    for(int i = 0; i < ni; i++){
        cin >> c >> x;
        if(c == 'P'){
            p.insert(x);
        } else {
            n.insert(x);
        }
    }

    long double time = 0;

    while(!p.empty() || !n.empty()){
        size_t ps = p.size();
        size_t ns = n.size();

        long double tp = t * 0.75;
        long double tn = t * 0.25;

        if(ps == 0){
            long double up = *n.begin();
            long double timePfile = t / ns;
            long double time_used = up / timePfile;

            multiset<long double> temp;
            for(auto it : n){
                if(it - up > 0) temp.insert(it - up);
            }
            n = temp;

            time += time_used;
        }
        else if(ns == 0){
            long double up = *p.begin();
            long double timePfile = t / ps;
            long double time_used = up / timePfile;

            multiset<long double> temp;
            for(auto it : p){
                if(it - up > 0) temp.insert(it - up);
            }
            p = temp;

            time += time_used;
        } 
        else {
            long double nextNP = *n.begin() / (tn / ns);
            long double nextP = *p.begin() / (tp / ps);

            if(nextNP < nextP){
                long double up = *n.begin();
                long double timePfile = tn / ns;
                long double time_used = up / timePfile;

                // Update n
                multiset<long double> tempN;
                for(auto it : n){
                    if(it - up > 0) tempN.insert(it - up);
                }
                n = tempN;

                // Update p
                multiset<long double> tempP;
                for(auto it : p){
                    if(it - tp / ps * time_used > 0) tempP.insert(it - tp / ps * time_used);
                }
                p = tempP;

                time += time_used;
            } else {
                long double up = *p.begin();
                long double timePfile = tp / ps;
                long double time_used = up / timePfile;

                // Update p
                multiset<long double> tempP;
                for(auto it : p){
                    if(it - up > 0) tempP.insert(it - up);
                }
                p = tempP;

                // Update n
                multiset<long double> tempN;
                for(auto it : n){
                    if(it - tn / ns * time_used > 0) tempN.insert(it - tn / ns * time_used);
                }
                n = tempN;

                time += time_used;
            }
        }
    }

    cout << fixed << setprecision(9) << time << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
