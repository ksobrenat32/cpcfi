// Problem link:
// https://cses.fi/problemset/task//1092

#include <bits/stdc++.h>
#include <stack>
#include <vector>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long n; cin >> n;

    stack<long> v1;
    stack<long> v2;

    // Sum of all digits with Gauss
    long sum = n * (n+1) / 2;
    long msum1 = sum / 2;
    long msum2 = sum / 2;

    for( long i = n; i >= 1; i--){
        if( (msum1 - i) >= 0){
            v1.push(i);
            msum1 -= i;
        } else {
            v2.push(i);
            msum2 -= i;
        }
    }

    if(msum1 != msum2){
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
    }

    cout << v1.size() << endl;
    while(v1.empty() == false){
        cout << v1.top() << " ";
        v1.pop();
    }

    cout << endl << v2.size() << endl;
    while(v2.empty() == false){
        cout << v2.top() << " ";
        v2.pop();
    }
    cout << endl;

}

int main(){
    int T=1;
    //cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}