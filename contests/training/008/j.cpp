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
    int pn, dn;
    cin >> pn >> dn;

    vi usage(dn);
    vi plate(pn,0);

    // Read the usage on days
    for(int i=0; i<dn; i++){
        cin >> usage[i];
    }

    // For each day
    for(int i=0; i<dn; i++){
        // Add one to the top plates
        for(int j=0; j<usage[i]; j++){
            plate[j]++;
        }

        // Sort the top usage[i] plates to simulate worst case
        sort(plate.begin(), plate.begin()+usage[i]);
    }

    // Get the biggest
    cout << *(max_element(plate.begin(), plate.end())) << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
