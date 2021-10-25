
//Range Sum Queries:
struct SegTree{
    ll base;
    vector<ll> tree;
    void update(ll i, ll value){
        ll pos=base+i;
        ll delta=value-tree[pos];
        while(pos>0){
            tree[pos]+=delta;
            pos/=2;
        }
    }
    ll query(ll ql, ll qr, ll nl, ll nr, ll node){
        if(ql>nr || qr<nl){
            return 0;
        }
        if(ql<=nl && nr<=qr){
            return tree[node];
        }
        ll mid=(nl+nr)/2;
        return query(ql,qr,nl,mid,2*node)+query(ql,qr,mid+1,nr,2*node+1);
    }
    SegTree(vector<ll> a){
        ll n=a.size();
        base=1;
        while(2*base<n){
            base*=2;
        }
        base*=2;
        tree.resize(2*base);
        for(ll i=0;i<n;i++){
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
5) Do appropriate changes for range min queries
*/

//Range Min Queries
struct SegTree{
    ll base;
    vector<ll> tree;
    void update(ll i, ll value){
        ll pos=base+i;
        tree[pos]=value;
        pos/=2;
        while(pos>0){
            tree[pos]=min(tree[2*pos],tree[2*pos+1]);
            pos/=2;
        }
    }
    ll query(ll ql, ll qr, ll nl, ll nr, ll node){
        if(ql>nr || qr<nl){
            return INF;
        }
        if(ql<=nl && nr<=qr){
            return tree[node];
        }
        ll mid=(nl+nr)/2;
        return min(query(ql,qr,nl,mid,2*node),query(ql,qr,mid+1,nr,2*node+1));
    }
    SegTree(vector<ll> a){
        ll n=a.size();
        base=1;
        while(2*base<n){
            base*=2;
        }
        base*=2;
        tree.resize(2*base,INF);
        for(ll i=0;i<n;i++){
            update(i,a[i]);
        }
    }
};



struct SegTree{
    int base;
    vector<int> tree;
    void update(int i, int value){
        int pos=base+i;
        int new_gcd=__gcd(value,tree[pos]);
        tree[pos]=new_gcd;
        pos/=2;
        while(pos>0){
            tree[pos]=__gcd(tree[2*pos],tree[2*pos+1]);
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
        return __gcd(query(ql,qr,nl,mid,2*node),query(ql,qr,mid+1,nr,2*node+1));
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
