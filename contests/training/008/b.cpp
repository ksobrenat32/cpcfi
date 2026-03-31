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

// <number, set of integers with number>
map<int, set<int>> m;
vpii res;

bool needs_problem_operation(int x, int y, int xi, int yi){
    //cout << xi << " " << yi << endl;
    if(x == y || x+1 == y){
        if(xi < yi){
            return false;
        } else {
            return true;
        }
    }
    return true;
}

pii problem_operation(int x, int y){
    int nx, ny;
    nx = floor((float)(x + y) / 2.0);
    ny = ceil((float)(x + y) / 2.0);
    return {nx, ny};
}

bool apply_problem_operation(){
    // Biggest value on map
    int biggest = m.rbegin()->first;
    // Biggest value index on map that is the leftest
    int biggest_index = *(m.rbegin()->second.begin());

    // Smallest value on map
    int smallest = m.begin()->first;
    // Smallest value index on map that is rightest
    int smallest_index = *(m.begin()->second.rbegin());

    //cout << "BB: " << biggest << endl;
    //cout << "SM: " << smallest << endl;
    
    // Is the operation is needed, apply and return true
    if(needs_problem_operation(smallest, biggest, smallest_index, biggest_index)){
        // Delete olds
        m[biggest].erase(biggest_index);
        if(m[biggest].size() == 0){
            m.erase(biggest);
        }

        m[smallest].erase(smallest_index);
        if(m[smallest].size() == 0){
            m.erase(smallest);
        }
        
        if(smallest_index > biggest_index){
            swap(smallest_index, biggest_index);
        }
        res.push_back({smallest_index, biggest_index});
        
        // Generate new values
        pii nw = problem_operation(smallest, biggest);
        
        
        /*
        cout << "NEW VALUES" << endl;
        cout << nw.first << " " << smallest_index << endl;
        cout << nw.second << " " << biggest_index << endl;
        */

        // Add the new values
        m[nw.first].insert(smallest_index);
        m[nw.second].insert(biggest_index);
        return true;
    } 
    // If the operation is not really needed we are done
    else {
        //cout << "END: " << smallest_index << " " << biggest_index << endl;
        return false;
    }
}

inline void solve(){
    int n; cin >> n;
    int tmp;
    
    FO(i, n){
        cin >> tmp;
        m[tmp].insert(i);
    }

    while(apply_problem_operation()){
        //sleep(1);
        // If just one number
        if(m.size() == 1){
            break;
        }
    }

    cout << res.size() << endl;
    FO(i, res.size()){
        cout << res[i].first+1 << " " << res[i].second+1 << endl;
    }
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
