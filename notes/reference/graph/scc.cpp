typedef long long ll;
typedef vector<int> vec;
const ll mod=1e9+7;
const int MAX=1e5+3;
vector<vector<int>> g(MAX);
vector<vector<int>> r(MAX);
vector<int> id(MAX);
bool visitados[MAX]={false};
vector<int> l;

void dfs(int s){
    visitados[s]=true;
    for(int c:g[s]){
        if(!visitados[c]) dfs(c);
    }
    l.push_back(s);
}

void rdfs(int s,int d)
{
    visitados[s]=true;
    id[s]=d;
    for(int c:r[s])
    {
        if(!visitados[c]) rdfs(c,d);
    }
}
