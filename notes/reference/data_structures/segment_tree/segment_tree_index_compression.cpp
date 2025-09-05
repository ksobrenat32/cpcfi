typedef long long ll;
typedef vector<int> vec;
typedef vector<pair<int,int>> vpii;
const ll mod=1e9+7;
const int MAX=4e5+3;
const int limit=2e5+3;
const int TAM=2e5+1;
ll t[4*MAX];
//ascii https://elcodigoascii.com.ar/


void update(int root,int l,int r,int pos,int val)
{
    if(l==r)
    {
        t[root]+=val;
        return;
    }
    int mid=(l+r)/2;
    if(pos>mid)
    {
        update(2*root+1,mid+1,r,pos,val);
    }
    else{
        update(2*root,l,mid,pos,val);
    }
    t[root]=t[2*root]+t[2*root+1];
}

ll consult(int root,int l,int r, int a,int b)
{
    if(a>b) return 0;
    if(l==a && r==b) return t[root];
    int mid=(l+r)/2;
    return consult(2*root,l,mid,a,min(b,mid))+
    consult(2*root+1,mid+1,r,max(mid+1,a),b);
}

inline void solve()
{
   int n,m,index;
   cin>>n>>m;
   vector<ll> arr(n);
   vector<tuple<char,ll,ll>> queries(m);
   set<ll> salary;
   memset(t,0,sizeof(t));
   FO(i,n){
        ll aux; cin>>aux;
        arr[i]=aux;
        salary.insert(aux);
   }
   FO(i,m)
   {
        char a;
        ll b,c;
        cin>>a>>b>>c;
        queries[i]=make_tuple(a,b,c);
        if(a=='!') salary.insert(c);
   }

   vector<ll> coord(all(salary));
   int tn=coord.size();
   //FO(i,tn) cout<<coord[i]<<" ";
   //cout<<endl;
   FO(i,n)
   {
        index=lower_bound(all(coord),arr[i])-coord.begin();
        update(1,0,tn-1,index,1);
   }
   FO(i,m)
   {
        char a=get<0>(queries[i]);
        ll b=get<1>(queries[i]);
        ll c=get<2>(queries[i]);
        if(a=='?'){
            b=lower_bound(all(coord),b)-coord.begin();
            c=(upper_bound(all(coord),c)-coord.begin())-1;
            if(b==tn || c==tn ){
                cout<<0<<endl;
            }
            else cout<<consult(1,0,tn-1,b,c)<<endl;
        }
        else{
            index=lower_bound(all(coord),arr[b-1])-coord.begin();
            update(1,0,tn-1,index,-1);
            arr[b-1]=c;
            index=lower_bound(all(coord),arr[b-1])-coord.begin();
            update(1,0,tn-1,index,1);

        }
   }

}
