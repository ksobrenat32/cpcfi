#include <bits/stdc++.h>
using namespace std;
const int N = 6e4;

// by israel5468

int main() {
    long long bolsa[N];
    int k=0, p=0; cin >> k >>p;
    bolsa[0]=1;
    //OBSERVAR SI ENTRE LAS BOLSAS QUE NOS DAN PODEMOS
    //OBTENER EL RESULTADO QUE NOS PIDEN (MIXTO)
    for (int i = 0; i < p; i++)
    {
        int arroz; cin >> arroz;
        for (int j = arroz; j < N; j++)
        {
            if (bolsa[j-arroz])
            {
                bolsa[j] = 1;
            }
            
        }
        
    }
    //CASO PARA VER CUANTAS DE UNA MISMA BOLSA PODEMOS AGARRAR
    for (int i = 0; i < k; i++)
    {
        int arroz; cin >> arroz;
        int resul = -1;
        for (int j = arroz; j < N; j++)
        {
            if(bolsa[j]==1)
            {
                resul = j;
                break;
            }
        }
        cout << resul-arroz << endl; //OBSERVAR EL GASTO QUE NOS VA A DAR
    }
}