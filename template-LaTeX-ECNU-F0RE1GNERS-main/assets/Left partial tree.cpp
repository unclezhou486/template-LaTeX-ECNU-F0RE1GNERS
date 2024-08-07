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
struct node{int ch[2],d,val;}t[N];
int f[N],ff[N];
int find(int x){
  if(f[x]==x)return x;
  return f[x]=find(f[x]);
}
int& rs(int x){return t[x].ch[t[t[x].ch[1]].d<t[t[x].ch[0]].d];}
int merge(int x,int y){
  if(!x||!y)return x|y;
  if(t[x].val>t[y].val||(t[x].val==t[y].val&&x>y))swap(x,y);
  f[y]=find(x);
  rs(x)=merge(rs(x),y);
  t[x].d=t[rs(x)].d+1;
  return x;
}
void solve(){
  int n,m;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>t[i].val;t[i].d=1;
    f[i]=i;ff[i]=1;
  }
  cin>>m;
  while(m--){
    char op;
    int x,y;
    cin>>op;
    if(op=='M'){
      cin>>x>>y;
      if(!ff[x]||!ff[y]||find(x)==find(y))continue;
      merge(find(x),find(y));
    }else {
      cin>>x;
      if(!ff[x]){
        cout<<"0\n";
        continue;
      }
      int k=find(x);
      cout<<t[k].val<<"\n";
      f[t[k].ch[0]]=t[k].ch[0];
      f[t[k].ch[1]]=t[k].ch[1];
      f[k]=merge(t[k].ch[0],t[k].ch[1]);
      ff[k]=0;
    }
  }
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