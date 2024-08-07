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
const int N=2e5+5;
const int M=1e5+5;
const int INF=2e9;
//const int p=998244353;
const int MOD=1e9+7;
const double DARW=0.97;
struct node{int l,r,x,h;}tr[N<<6];
int head[N],tot,n,m;
void build(int& p,int l,int r){
	if(!p)p=++tot;
	if(l==r){tr[p].x=l;return;}
	int mid=(l+r)>>1;
	build(tr[p].l,l,mid);
	build(tr[p].r,mid+1,r);
}
void change(int p1,int& p2,int l,int r,int x,int f,int h){
	if(!p2)p2=++tot;
	if(l==r){tr[p2].x=f,tr[p2].h=h;return;}
	int mid=(l+r)>>1;
	if(x<=mid)change(tr[p1].l,tr[p2].l,l,mid,x,f,h),tr[p2].r=tr[p1].r;
	else change(tr[p1].r,tr[p2].r,mid+1,r,x,f,h),tr[p2].l=tr[p1].l;
}
pii find(int p,int l,int r,int x){
	if(l==r)return {tr[p].x,tr[p].h};
	int mid=(l+r)>>1;
	if(x<=mid)return find(tr[p].l,l,mid,x);
	else return find(tr[p].r,mid+1,r,x);
}
pii findfa(int p,int x){
	pii y=find(p,1,n,x);
	if(x==y.first)return y;
	return findfa(p,y.first);
}
void merge(int p1,int& p2,int x,int y){
	pii px=findfa(p1,x),py=findfa(p1,y);
	if(px.second>py.second)change(p1,p2,1,n,py.first,px.first,py.second);
	else if(px.second<py.second)change(p1,p2,1,n,px.first,py.first,px.second);
	else {
		int p=0;
		change(p1,p,1,n,py.first,px.first,py.second);
		change(p,p2,1,n,px.first,px.first,px.second+1);
	}
}
void solve(){
	cin>>n>>m;
	build(head[0],1,n);
	for(int i=1;i<=m;i++){
		int op;
		cin>>op;
		if(op==1){
			int x,y;
			cin>>x>>y;
			merge(head[i-1],head[i],x,y);
		}else if(op==2){
			int k;
			cin>>k;
			head[i]=head[k];
		}else {
			int x,y;
			cin>>x>>y;
			head[i]=head[i-1];
			if(findfa(head[i],x).first==findfa(head[i],y).first)cout<<"1\n";
			else cout<<"0\n";
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