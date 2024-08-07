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
#include<functional>
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=2e5+5;
const int M=5e6+5;
const int INF=1e9;
//const int p=998244353;
const int MOD=1e9+7;
const double DARW=0.97;
const double eps=1e-12;
int ans[N],f[N];
vector<int>t[N];
struct node{int x,val;bool operator<(const node& a)const{return val>a.val;}};
struct edge{int v,w;};
vector<edge>e[N];
priority_queue<node>q;
void dij(){
    while(q.size()&&f[q.top().x])q.pop();
    if(q.empty())return;
    node x=q.top();
    q.pop();
    f[x.x]=1;
    for(auto u:e[x.x]){
        if(u.w+ans[x.x]<ans[u.v]){
            ans[u.v]=u.w+ans[x.x];
            q.push({u.v,ans[u.v]});
        }
    }
    dij();
}
void solve(){
    int h,a,b,c;    
    cin>>h>>a>>b>>c;
    if(a<b)swap(a,b);
    if(b<c)swap(b,c);
    for(int i=0;i<c;i++)e[i].push_back({(i+a)%c,a}),e[i].push_back({(i+b)%c,b}),ans[i]=2e18;
    ans[0]=1;
    q.push({0,ans[0]});
    dij();
    int as=0;
    for(int i=0;i<c;i++){
        if(h>=ans[i])
        as+=(h-ans[i])/c+1;
    }
    cout<<as<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1,k=1;
	//cin>>t;
	while(t--)solve();
}