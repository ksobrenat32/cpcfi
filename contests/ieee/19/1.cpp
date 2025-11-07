#include<bits/stdc++.h>

using namespace std;

#define all(b) b.begin(), b.end()

inline void solve(){
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int &x : a) cin>>x;

    for(int i=0; i<q; i++){
        int u; cin>>u;
        auto l = lower_bound(all(a),u) ;
        auto r = upper_bound(all(a),u);

        if(l == a.end() or a[l-a.begin()] != u or a[r-a.begin()-1] != u){
            cout<<-1<<" "<<-1<<endl;
        }else if(a[l-a.begin()] == u and r == a.end()){
            cout<< (l-a.begin())+1<<" "<<n<<endl;
        }
        
        else{
            cout<< (l-a.begin())+1<<" "<<(r-a.begin())<<endl;
        }
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}