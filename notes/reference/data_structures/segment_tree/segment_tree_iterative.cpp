int segtree[2*100000 + 5];

    void build(vector<int> &arr, int n){
        for(int i=0; i<n; i++)
            segtree[n+i] = arr[i];

        for(int i=n-1; i>=1; i--)
            segtree[i] = max(segtree[2*i], segtree[2*i+1]);
    }

    void update(int pos, int value, int n){
        pos+=n;
        segtree[pos] = value;

        while(pos>1){
            pos>>=1;
            segtree[pos] = max(segtree[2*pos],segtree[2*pos+1]);
        }
    }

    int query(int l, int r, int n){
        l+=n;
        r+=n;

        int mx = INT_MIN;

        while(l <= r){
            if(l % 2 == 1) mx = max(mx, segtree[l++]);
            if(r % 2 == 0) mx = max(mx, segtree[r--]);
            l >>= 1;
            r >>= 1;
        }

        return mx;
    }
