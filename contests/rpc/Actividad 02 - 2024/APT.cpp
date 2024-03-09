#include<bits/stdc++.h>

using namespace std;

#define FO(i,b)   for(int i=0;i<b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define lFOR(i,b) for(int i=0;i<b;i--)
#define all(x)    x.begin(),x.end()
#define tam(x)    x.size()
#define LB(arr,x)  lower_bound(all(arr),x)-(arr).begin()
#define UB(arr,x)  upper_bound(all(arr),x)-(arr).begin()
typedef long long ll;
typedef vector<int> vec;

//ascii https://elcodigoascii.com.ar/

inline void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> packages(n);
    double total=0;

    FO(i,n){
        cin >> packages[i];
        total += packages[i];
    }

    sort(all(packages));
    reverse(all(packages));
    double sum=0;

    FO(i, min(m+k, n)){
        sum += packages[i];
    }

    //cout << "SUM: " << sum << endl;
    //cout << "TOTAL: " << total << endl;

    sum /= total;
    sum *= 100;
    cout << setprecision(10) << sum <<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}