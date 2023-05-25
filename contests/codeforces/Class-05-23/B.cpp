// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/445186/problem/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

void invert(bool &x){
    if( x ){
        x = false;
    } else {
        x = true;
    }
}

inline void solve(){
    int n; cin >> n;
    string a, b; cin >> a >> b;

    if( a == b ){
        cout << "YES" << endl;
        return;
    }

    if( n % 2 != 0){
        if(a[n-1] != b[n-1]){
            cout << "NO" << endl;
            return;
        } else {
            n--;
        }
    }

    int zero = 0, one = 0;
    for( int i = 0; i < n; i++){
        if( a[i] == '0'){
            zero++;
        } else {
            one++;
        }
    }

    bool flag = false;

    for(int i = n-2; i >= 0; i-=2){
        if( flag ){
            if(a[i] != b[i] && a[i+1] != b[i+1]){
                if( a[i] != '0'){
                    zero--;
                } else {
                    one--;
                }
                if( a[i+1] != '0'){
                    zero--;
                } else {
                    one--;
                }
                continue;
            } else if (a[i] == b[i] && a[i+1] == b[i+1]){
                if( zero == one ){
                    invert(flag);
                    if( a[i] == '0'){
                        zero--;
                    } else {
                        one--;
                    }
                    if( a[i+1] == '0'){
                        zero--;
                    } else {
                        one--;
                    }
                    continue;
                } else {
                    cout << "NO" << endl;
                    return;
                }
            } else {
                cout << "NO" << endl;
                return;
            }
        } else {
            if(a[i] == b[i] && a[i+1] == b[i+1]){
                if( a[i] == '0'){
                    zero--;
                } else {
                    one--;
                }
                if( a[i+1] == '0'){
                    zero--;
                } else {
                    one--;
                }
                continue;
            } else if (a[i] != b[i] && a[i+1] != b[i+1]){
                if( zero == one ){
                    invert(flag);
                    if( a[i] != '0'){
                        zero--;
                    } else {
                        one--;
                    }
                    if( a[i+1] != '0'){
                        zero--;
                    } else {
                        one--;
                    }
                    continue;
                } else {
                    cout << "NO" << endl;
                    return;
                }
            } else {
                cout << "NO" << endl;
                return;
            }
        }

    }

    cout << "YES" << endl;
}
        

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
