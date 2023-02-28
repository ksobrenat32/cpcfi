#include <bits/stdc++.h>

using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

int bs(int N, int x, vector<int> v){
    int R = N-1;
    int L = 0;
    int mid;

    while(L <= R){
        mid = L + (R - L) / 2;

        if(v[mid] == x){
            return mid;
        } 
        
        if(v[mid] < x ){
            L = mid + 1 ;
        } else {
            R = mid - 1;
        }
    }

    return -1;
}

int lb(int N, int x, vector<int> v){
    int R = N-1;
    int L = 0;
    int mid;

    while(L <= R){
        mid = L + (R - L) / 2;

        if(v[mid] == x){
            while( v[mid] == x){
                mid--;
            }
            return mid+1;
        } 
        
        if(v[mid] < x ){
            L = mid + 1 ;
        } else {
            R = mid - 1;
        }
    }

    return -1;
}

int ub(int N, int x, vector<int> v){
    int R = N-1;
    int L = 0;
    int mid;

    while(L <= R){
        mid = L + (R - L) / 2;

        if(v[mid] == x){
            while( v[mid] == x){
                mid++;
            }
            return mid-1;
        } 
        
        if(v[mid] < x ){
            L = mid + 1 ;
        } else {
            R = mid - 1;
        }
    }

    return -1;
}

inline void solve(){

    int n;
    cin >> n;
    vector<int> v(n);
    FO(i,n){
        cin >> v[i];
    }

    int x;
    cin >> x;

    cout << bs(n,x,v) << endl;
    cout << ub(n,x,v) << endl;
    cout << lb(n,x,v) << endl;
}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
