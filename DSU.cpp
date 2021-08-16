struct DSU{
    vector<int> par,rank;
    DSU(int n){
        par.resize(n);
        rank.resize(n);
        for(int v=0;v<n;v++){
            par[v] = v;
            rank[v] = 0;
        }
    }
    int find(int v) {
        if (v == par[v]){
            return v;
        }
        return par[v] = find(par[v]);
    }
    void merge(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b])
            swap(a, b);
            par[b] = a;
            if (rank[a] == rank[b]){
                rank[a]++;
            }
        }   
    }
};
