#include <bits/stdc++.h>
using namespace std;

// by israel5468

int MOD = 1e9+7;

void solve(){
    int n; cin >> n;
    int arr[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    sort(arr,arr+n,greater<int>());
    sort(arr2,arr2+n,greater<int>());
    long long cont=0, aux=0;
    long long result = 1;
    for (int i = 0; i < n; i++)
    {
        while ((arr2[i]<arr[aux]) && (aux < n))
        {
            cont++;
            aux++;
        }
        result=(result*(cont-i)%MOD)%MOD;
    }
    cout << result << endl;
    
}

int main()
{
	int t; cin >> t;
	while (t--)
    {
        solve();
    }
	return 0;
}