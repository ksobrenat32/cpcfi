#include <bits/stdc++.h>
using namespace std;

// By isral5468

void solve()
{
    int tam; cin >> tam;
    int arr[tam];
    for (int i = 0; i < tam; i++)
    {
        cin >> arr[i];
    }
    int t = -1;
    for (int i = 0; i <= tam; i++)
    {
        int cont =0;
        for (int j = 0; j < tam; j++)
        {
            if (arr[j]>i) cont++;
        }
        if (cont == i)
            {
                t = cont;
                break;
            }
    }
    cout << t << endl;
}

int main()
{
    int n; cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}