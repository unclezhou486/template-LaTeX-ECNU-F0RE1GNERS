#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<unordered_map>
#include<deque>
#include<iomanip>
#include<bitset>
#define ll long long
#define int long long
using namespace std;
const int N=1e6+5;
const int M=1e8+5;
const int INF=1e9;
const int p=998244353;
const double DARW=0.97;
int tree[N][30],bh,f[N],fail[N],ff[N],lst_[N];
queue<int>q;
void insert(string s){
  int p=0;
  for(int i=0;i<s.length();i++){
    if(!tree[p][s[i]-'a'])tree[p][s[i]-'a']=++bh;
    p=tree[p][s[i]-'a'];
  }
  f[p]++;
}
void build(){
  for(int i=0;i<26;i++)if(tree[0][i])q.push(tree[0][i]);
  while(!q.empty()){
    int p=q.front();
    q.pop();
    for(int i=0;i<26;i++){
      if(tree[p][i])q.push(tree[p][i]),fail[tree[p][i]]=tree[fail[p]][i];
      else tree[p][i]=tree[fail[p]][i];
    }
  }
}
void solve(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    string ss;
    cin>>ss;
    insert(ss);
  }
  build();
  string t;
  cin>>t;
  int ans=0;
  for(int i=0,j=0;i<t.length();i++){
    j=tree[j][t[i]-'a'];
    for(int u=j;u&&!ff[u];u=fail[u]){
      ans+=f[u],ff[u]=1;
    }
  }
  cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	  int t=1,k=1;
	  //cin>>t;
	  while(t--){
      solve();
    }
}