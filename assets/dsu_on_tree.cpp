#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
vector<int>e[N];
int n,tot;
int a[N],cnt[N],sz[N],son[N],idx[N],r[N],rth[N],num[N],ans[N];
multiset<int>s;
void dfs1(int x,int fa){
    sz[x]=1;
    idx[x]=++tot;
    rth[tot]=x;
    for(auto u:e[x]){
        if(u==fa)continue;
        dfs1(u,x);
        if(!son[x]||sz[son[x]]<sz[u])son[x]=u;
        sz[x]+=sz[u];
    }
    r[x]=tot;
}
void dfs2(int x,int fa,int f){
    for(auto u:e[x]){
        if(u==son[x]||u==fa)continue;
        dfs2(u,x,0);
    }
    if(son[x])dfs2(son[x],x,1);
    for(auto u:e[x]){
        if(u==son[x]||u==fa)continue;
        for(int i=idx[u];i<=r[u];i++){
            s.erase(cnt[a[rth[i]]]);
            num[cnt[a[rth[i]]]]-=a[rth[i]];
            cnt[a[rth[i]]]++;
            s.insert(cnt[a[rth[i]]]);
            num[cnt[a[rth[i]]]]+=a[rth[i]];
        }
    }
    s.erase(cnt[a[x]]);
    num[cnt[a[x]]]-=a[x];
    cnt[a[x]]++;
    s.insert(cnt[a[x]]);
    num[cnt[a[x]]]+=a[x];
    ans[x]=num[*s.rbegin()];
    if(!f){
        for(int i=idx[x];i<=r[x];i++){
            s.erase(cnt[a[rth[i]]]);
            num[cnt[a[rth[i]]]]-=a[rth[i]];
            cnt[a[rth[i]]]--;
            s.insert(cnt[a[rth[i]]]);
            num[cnt[a[rth[i]]]]+=a[rth[i]];
        }
    }
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1,u,v;i<n;i++)cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
    dfs1(1,0);
    dfs2(1,0,0);
    for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
}