// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/444610/problem/L

// by israel5468

#include <bits/stdc++.h>
using namespace std;

int main() {
    string pal;
    int n;
    cin >> pal >> n;
    int pos = 0; //posicion actual
    int result = 0; //resultado
    while (pos < pal.size()) 
    {
        int mx = n;
        for (int i = 1; i <=n; i++) 
        {
            int aux = pos;
            while ((pal[aux] == pal[aux+i]) && (aux<pal.size())) aux++;
            mx = max(mx, aux-pos + i);
        }
        result++;
        pos=pos+mx;
    }
    cout << result << endl;
}