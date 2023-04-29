// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/440974/problem/C

#include <bits/stdc++.h>
using namespace std;

bool es_primo(int t){
    if(t%2 == 0){
        return false;
    } else {
        for(int i=3; i*i <=t; i+=2){
            if((t%i)==0){
                return false;
            }
        }
    }
    return true;
}


void solve(vector<int> &memo, int &memoTop){
    // Intervalos
    int x,y;
    cin >> x >> y;

    int res;

    // Ya calculado
    if(y <= memoTop){
        if( memo[x] == memo[y]){
            res = memo[y] - memo[y-1];
        } else {
            res = memo[y] - memo[x-1];
        }
    } else {
        // Calcular todos los primos hasta ese numero
        int i;
        for(i = memoTop + 1; i <= y; i++){
            if(es_primo(i)){
                memo[i] = memo[i-1] + 1;
            } else {
                memo[i] = memo[i-1];
            }
        }
        memoTop = i - 1;

        if( memo[x] == memo[y]){
            res = memo[y] - memo[y-1];
        } else {
            res = memo[y] - memo[x-1];
        }
    }
    cout << res <<endl;
}


int main()
{
    int n;
    cin >> n;
    vector<int> memo(1000000);
    int memoTop=2;

    memo[0] = 0;
    memo[1] = 0;
    memo[2] = 1;

    while (n--)
    {
        solve(memo,memoTop);
    }

    /*
    // Print memo
    for(int i = 0; i < memoTop; i++){
        cout << "MEMO[" << i << "]: " << memo[i] << endl;;
    }
    */

    return 0;
}