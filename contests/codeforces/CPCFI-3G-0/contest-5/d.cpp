#include <bits/stdc++.h>
using namespace std;

// Generate snow map
array<array<bool, 1000>, 1000> m;
    
void dfs(int x, int y){
    // Flags as visited
    m[x][y]=0;

    // Visits al X snowdrifts
    for(int i=0;i<1000;i++){
        if(m[x][i] == 1){
            dfs(x,i);
        }
    }

    // Visits al Y snowdrifts
    for(int i=0;i<1000;i++){
        if(m[i][y] == 1){
            dfs(i,y);
        }
    }

}

int main(){
    int n;
    cin >> n;


    for(int i=0;i<n;i++){
        int x;
        int y;
        cin>>x>>y;

        // Flag a snow drift
        m[x-1][y-1] = 1;
    }
 
    // New snow drifts to create
    int nsd=-1;
    
    for(int i=0;i<1000;i++){
        for(int j=0;j<1000;j++){
            // If ther is a snow drift mark a new snow drift and visit it
            if(m[i][j] == 1){
                nsd++;
                dfs(i,j);
            }
        }
    }

    cout<<nsd<<endl;

    return 0;
}
