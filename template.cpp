#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
#define int long long int
#define double long double
 
#define all(x) (x).begin(), (x).end()
#define R(a) int a; cin>>a;
#define RemoveDuplicates(a) a.resize(unique(all(a))-a.begin())
#define endl '\n'
 
#ifndef ONLINE_JUDGE
template<typename T>    
void __p(T a) {
  cerr<<a;
}
template<typename T, typename F>
void __p(pair<T, F> a) {
  cerr<<"[";
  __p(a.first);
  cerr<<",";
  __p(a.second);
  cerr<<"]";
}
template<typename T>
void __p(std::vector<T> a) {
  cerr<<"[";
  for(auto it=a.begin(); it<a.end(); it++)
    __p(*it),cerr<<",]"[it+1==a.end()];
}
template<typename T, typename ...Arg>
void __p(T a1, Arg ...a) {
  __p(a1);
  __p(a...);
}
template<typename Arg1>
void __f(const char *name, Arg1 &&arg1) {
  cerr<<name<<" : ";
  __p(arg1);
  cerr<<endl;
}
template<typename Arg1, typename ... Args>
void __f(const char *names, Arg1 &&arg1, Args &&... args) {
  int bracket=0,i=0;
  for(;; i++)
    if(names[i]==','&&bracket==0)
      break;
    else if(names[i]=='(')
      bracket++;
    else if(names[i]==')')
      bracket--;
  const char *comma=names+i;
  cerr.write(names,comma-names)<<" : ";
  __p(arg1);
  cerr<<" | ";
  __f(comma+1,args...);
}
#define trace(...) cerr<<"Line:"<<__LINE__<<" ", __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...)
#endif

void precompute(){

}
void test_case(){

}
// The Learning Paradox: 
// the more you struggle and fail while you’re trying to master new information,
// the better you’re likely to recall and apply that information later.
int32_t main(){
  
  srand(time(0));
  // Remove for Interactive Problems
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
 
  precompute();
  
  int T=1;
  // cin>>T;
  for(int TT=1; TT<=T; TT++){
    test_case();
  }
  cerr<<"Time : "<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms\n";
 
  return 0;
}
