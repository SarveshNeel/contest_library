struct Trie{
    Trie* child[26];
    bool end;
};
Trie* getnode(){
    Trie* p = new Trie;
    for(ll i=0;i<26;i++){
        p->child[i]=NULL;
    }
    p->end=false;
    return p;
}
void insert(Trie* root, string s){
    Trie* p = root;
    for(ll i=0;i<s.size();i++){
        ll ch=s[i]-'a';
        if(p->child[ch]==NULL){
            Trie* pnew = getnode();
            p->child[ch]=pnew;
        }
        p=p->child[ch];
    }
    p->end=true;
}
bool ispresent(Trie* root, string s){
    Trie* p = root;
    for(ll i=0;i<s.size();i++){
        ll ch=s[i]-'a';
        if(p->child[ch]==NULL){
            return false;
        }
        p=p->child[ch];
    }
    return p->end;
}

