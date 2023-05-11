// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/443124/problem/A

// By israel5468

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string pal; cin >> pal;
    int aux=0,aux2=0,pos=0;
        for (int i = 0; i < pal.size(); i++)
        {
        if ((pal[i] == 'A' && pal[i+1] == 'B'))
            {
            pos=i;
            aux=1;
            break;
            }
        }
    if (aux==1)
        {
            for (int j = pos+2; j < pal.size(); j++)
            {
                if (pal[j] == 'B' && pal[j+1] == 'A')
                {
                aux2=1;
                break;
                }
            }
        }
    if(aux2==0)
    {
        for (int i = 0; i < pal.size(); i++)
        {
            if (pal[i] == 'B' && pal[i+1] == 'A')
            {
                pos=i;
                aux=2;
                break;
            }
        }
        if(aux==2)
            {
                for (int j = pos+2; j <pal.size(); j++)
                {
                    if (pal[j] == 'A' && pal[j+1] == 'B')
                    {
                        aux2=1;
                        break;
                    }
                    
                }
                
            }
    }
        if (aux2==1) cout << "YES" << endl;
        else cout << "NO" << endl; 
     return 0;
}