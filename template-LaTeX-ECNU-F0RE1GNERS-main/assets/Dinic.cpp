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
const int N=2e3+5;
const int M=1e5+5;
const int INF=2e9;
//const int p=998244353;
const int MOD=1e9+7;
const double DARW=0.97;
int tot,m,n,s,t;
struct edge{
	int v,w,nxt;
}e[N<<2];
int head[N],a[N],b[N],vis[N],d[N];
set<int>ans;
void add(int u,int v,int w){
	e[tot].v=v;
	e[tot].w=w;
	e[tot].nxt=head[u];
	head[u]=tot++;
}
int bfs(){
	ans.clear();
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s);
	vis[s]=1;
	d[s]=0;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i!=-1;i=e[i].nxt){
			if(vis[e[i].v]||e[i].w==0)continue;
			ans.insert(e[i].v);
			d[e[i].v]=d[x]+1;
			vis[e[i].v]=1;
			q.push(e[i].v);
		}
	}
	//cout<<d[t]<<"\n";
	//cout<<t<<"\n";
	return vis[t];
}
int dfs(int x,int a){
	if(x==t||a==0)return a;
	int flow=0,f;
	for(int i=head[x];i!=-1;i=e[i].nxt){
		if(d[x]+1==d[e[i].v]&&(f=dfs(e[i].v,min(a,e[i].w)))>0){
			e[i].w-=f;
			e[i^1].w+=f;
			a-=f;
			flow+=f;
			if(a==0)break;
		}
	}
	return flow;
}
int Dinic(){
	int flow=0;
	while(bfs()){
		flow+=dfs(s,INF);
	}
	return flow;
}
void solve(){
	cin>>m>>n;
	int as=0;s=0,t=n+m+1;
	memset(head,-1,sizeof(head));
	string str;
	stringstream ss;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		as+=a[i];
		add(0,i,a[i]);
		add(i,0,0);
		ss.clear();
		getline(cin,str);
		ss<<str;
		int x;
		while(ss>>x){
			//cout<<x<<"\n";
			add(i,x+m,INF);
			add(x+m,i,0);
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		add(i+m,n+m+1,b[i]);
		add(n+m+1,i+m,0);
	}
	as-=Dinic();
	vector<int>ans1,ans2;
	for(auto u:ans){
		if(u<=m)ans1.push_back(u);
		else ans2.push_back(u-m);
	}
	for(auto u:ans1)cout<<u<<" ";
	cout<<'\n';
	for(auto u:ans2)cout<<u<<" ";
	cout<<'\n';
	cout<<as<<"\n";
}	
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tt=1,k=1;
	//cin>>t;
	while(tt--){
		solve();
	}
}