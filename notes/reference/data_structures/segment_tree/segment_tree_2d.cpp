typedef long long ll;
typedef vector<int> vec;
const ll mod=1e9+7;
const int TAM=1e3+1;
//ascii https://elcodigoascii.com.ar/
vector<vector<int>> forest(TAM,vector<int> (TAM));
ll t[4*TAM][4*TAM];
int n;

void buildNode(int root,int l,int r,int node,vector<int> &arr){
    if(l==r)
    {
        t[node][root]=arr[l];
        return;
    }
    int mid=(l+r)/2;
    buildNode(2*root,l,mid,node,arr);
    buildNode(2*root+1,mid+1,r,node,arr);
    t[node][root]=t[node][2*root]+t[node][2*root+1];
}

void build(int root,int l,int r,vector<vector<int>> &arr)
{
    if(l==r)
    {
        buildNode(1,0,n-1,root,arr[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*root,l,mid,arr);
    build(2*root+1,mid+1,r,arr);
    FO(i,4*TAM) t[root][i]=t[2*root][i]+t[2*root+1][i];

}

void updateNode(int root,int l,int r,int y,int node,int val)
{
    if(l==r)
    {
        t[node][root]=val;
        return;
    }
    int mid=(l+r)/2;
    if(y>mid)
    {
        updateNode(2*root+1,mid+1,r,y,node,val);
    }
    else{
        updateNode(2*root,l,mid,y,node,val);
    }
    t[node][root]=t[node][2*root]+t[node][2*root+1];
}

void update(int root,int l,int r,int x,int y,int val)
{
    if(l==r)
    {
        updateNode(1,0,n-1,y,root,val);
        return;
    }
    int mid=(l+r)/2;
    if(x>mid)
    {
        update(2*root+1,mid+1,r,x,y,val);
    }
    else{
        update(2*root,l,mid,x,y,val);
    }
    int i=0,j=n-1,Ndt=1,mid_aux;
    while(i!=j)
    {
        mid_aux=(i+j)/2;
        t[root][Ndt]=t[2*root][Ndt]+t[2*root+1][Ndt];
        if(y>mid_aux){
            i=mid_aux+1;
            Ndt=2*Ndt+1;
        }
        else{
            j=mid_aux;
            Ndt*=2;
        }
    }
    t[root][Ndt]=t[2*root][Ndt]+t[2*root+1][Ndt];
}

ll consultNode(int root,int l,int r,int node,int y1,int y2)
{
    if(y1>y2) return 0;
    if(l==y1 && r==y2) return t[node][root];
    int mid=(l+r)/2;
    return consultNode(2*root,l,mid,node,y1,min(y2,mid))+
    consultNode(2*root+1,mid+1,r,node,max(mid+1,y1),y2);
}

ll consult(int root,int l,int r, int x1,int x2,int y1,int y2)
{
    if(x1>x2) return 0;
    if(l==x1 && r==x2) return consultNode(1,0,n-1,root,y1,y2);
    int mid=(l+r)/2;
    return consult(2*root,l,mid,x1,min(x2,mid),y1,y2)+
    consult(2*root+1,mid+1,r,max(mid+1,x1),x2,y1,y2);
}
