// Problem link:
// https://codeforces.com/problemset/problem/1646/B

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

inline void solve(){
    long int n;
    cin >> n;

    vector<long long int> v(n);
    
    FO(i,n){
        cin >> v[i];
    }

    // Sort array
    sort(v.begin(),v.end());

    // Compare the three contiguos values
    vector <long long> prefix_sums = {0};
    for(int i = 0; i < n; i++){
        prefix_sums.push_back(prefix_sums.back() + v[i]);
    }
    vector <long long> suffix_sums = {0};
    for(int i = n - 1; i >= 0; i--){
        suffix_sums.push_back(suffix_sums.back() + v[i]);
    }

    for(int k = 1; k <= n; k++){
        if(2 * k + 1 <= n){
            long long blue_sum = prefix_sums[k + 1];
            long long red_sum = suffix_sums[k];
            if(blue_sum < red_sum){
                cout << "YES" << endl;
                return;
            }
		}
    }
    
    cout << "NO" << endl;
}

int main(){
    int T=1;
    cin>>T;
    FO(tc,T){
        solve();
    }
    return 0;
}
