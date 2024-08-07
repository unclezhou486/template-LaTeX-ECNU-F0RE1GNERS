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
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;
const int M=1e5+5;
const int INF=2e9;
//const int p=998244353;
const int MOD=1e9+7;
const double DARW=0.97;
int n,m,r,p,dfn;
int a[N],tr[N<<2],f[N],son[N],sz[N],idx[N],rnk[N],top[N],bj[N<<2],dep[N];
vector<int>e[N];
void dfs1(int x,int fa){
	f[x]=fa;
	sz[x]=1;
	dep[x]=dep[fa]+1;
	for(auto u:e[x]){
		if(u==fa)continue;
		dfs1(u,x);
		sz[x]+=sz[u];
		if(sz[u]>sz[son[x]])son[x]=u;
	}
}
void dfs2(int x,int fa){
	idx[x]=++dfn;
	rnk[dfn]=x;
	top[x]=fa;
	if(!son[x])return;
	dfs2(son[x],fa);
	for(auto u:e[x]){
		if(!idx[u])dfs2(u,u);
	}
}
void pushdown(int l,int r,int bh){
	if(l==r)return;
	int mid=(l+r)>>1;
	(tr[bh<<1]+=(mid-l+1)*bj[bh])%=p;
	(tr[(bh<<1)|1]+=(r-mid)*bj[bh])%=p;
	(bj[bh<<1]+=bj[bh])%=p;
	(bj[(bh<<1)|1]+=bj[bh])%=p;
	bj[bh]=0;
}
void build(int l,int r,int bh){
	if(l==r){tr[bh]=a[rnk[l]]%p;return;}
	int mid=(l+r)>>1;
	build(l,mid,bh<<1);
	build(mid+1,r,(bh<<1)|1);
	tr[bh]=(tr[bh<<1]+tr[(bh<<1)|1])%p;
}
void add(int l,int r,int x,int y,int bh,int k){
	if(x<=l&&y>=r){(tr[bh]+=(r-l+1)*k)%=p,(bj[bh]+=k)%=p;return;}
	pushdown(l,r,bh);
	int mid=(l+r)>>1;
	if(x<=mid)add(l,mid,x,y,bh<<1,k);
	if(y>mid)add(mid+1,r,x,y,(bh<<1)|1,k);
	tr[bh]=(tr[bh<<1]+tr[(bh<<1)|1])%p;
}
int find(int l,int r,int x,int y,int bh){
	if(x<=l&&y>=r)return tr[bh];
	pushdown(l,r,bh);
	int mid=(l+r)>>1,ans=0;
	if(x<=mid)(ans+=find(l,mid,x,y,bh<<1))%=p;
	if(y>mid)(ans+=find(mid+1,r,x,y,(bh<<1)|1))%=p;
	return ans;
}
void add(int x,int y,int z){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		add(1,n,idx[top[x]],idx[x],1,z);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	add(1,n,idx[x],idx[y],1,z);
}
int find(int x,int y){
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		(ans+=find(1,n,idx[top[x]],idx[x],1))%=p;
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	(ans+=find(1,n,idx[x],idx[y],1))%=p;
	return ans;
}
void solve(){
	cin>>n>>m>>r>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,u,v;i<n;i++)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
	dfs1(r,0);
	dfs2(r,r);
	build(1,n,1);
	for(int i=1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,y,z;
			cin>>x>>y>>z;
			add(x,y,z);
		}else if(op==2){
			int x,y;
			cin>>x>>y;
			cout<<find(x,y)<<"\n";
		}else if(op==3){
			int x,z;
			cin>>x>>z;
			add(1,n,idx[x],idx[x]+sz[x]-1,1,z);
		}else {
			int x;
			cin>>x;
			cout<<find(1,n,idx[x],idx[x]+sz[x]-1,1)<<"\n";
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