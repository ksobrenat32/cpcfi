inline void solve()
{
    int n; cin>>n;
    vector<int> normal(n);
    vector<int> rever(n);
    FO(i,n){
        cin>>normal[i];
        rever[i]=-normal[i];
    }
    ll sum = 0, max_sum = -1e9;
    ll sumr=0;
    for (int i = 0; i < n; i++) {
        sum += normal[i];
        max_sum = max(max_sum, sum);
        sumr+= rever[i];
        max_sum=max(max_sum,sumr);
        if(i%2==1){
            sum=max(sum,sumr);
            sumr=max(sum,sumr);
        }
        if (sum < 0) sum = 0;
        if (sumr<0) sumr=0;
    }
    cout<<max_sum<<endl;
    //Geeks for geeks
    //https://www.geeksforgeeks.org/cses-solutions-maximum-subarray-sum/
}
