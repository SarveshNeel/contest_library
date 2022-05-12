const ll N=1600;
ll p1,p2;
ll pw1[N],pw2[N];
struct hsh{
    ll n;
    vector<ll> val1;
    vector<ll> val2;
    hsh(string s){
        n=s.size();
        val1.resize(n+1);
        val2.resize(n+1);
        for(ll i=1;i<=n;i++){
            val1[i]=(val1[i-1]+s[i-1]*1LL*pw1[i-1])%mod;
            val2[i]=(val2[i-1]+s[i-1]*1LL*pw2[i-1])%mod;
        }
    }
    pair<ll,ll> sub(ll l, ll r){
        ll h1=((val1[r+1]-val1[l]+mod)*1LL*pw1[n-r])%mod;
        ll h2=((val2[r+1]-val2[l]+mod)*1LL*pw2[n-r])%mod;
        return {h1,h2};
    }
};
