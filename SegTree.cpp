struct SegTree{
    int base;
    vector<int> tree;
    void update(int i, int value){
        int pos=base+i;
        int delta=value-tree[pos];
        while(pos>0){
            tree[pos]+=delta;
            pos/=2;
        }
    }
    int query(int ql, int qr, int nl, int nr, int node){
        if(ql>nr || qr<nl){
            return 0;
        }
        if(ql<=nl && nr<=qr){
            return tree[node];
        }
        int mid=(nl+nr)/2;
        return query(ql,qr,nl,mid,2*node)+query(ql,qr,mid+1,nr,2*node+1);
    }
    SegTree(vector<int> a){
        int n=a.size();
        base=1;
        while(2*base<n){
            base*=2;
        }
        base*=2;
        tree.resize(2*base);
        for(int i=0;i<n;i++){
            update(i,a[i]);
        }
    }
};
/*
Note : 
1)array positions are 0-based indexing 
2)tree positions are 1-based indexing
3)query with 0....base-1 and not 0....n-1 in the root
4)base is power of 2 >= n
*/