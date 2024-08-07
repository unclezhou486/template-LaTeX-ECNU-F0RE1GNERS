#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int> 
using namespace std;
const int N=5e5+5;
int n,tot,idx[N],rth[N],d[N],f[N][100],lg[N],w[N][100];
vector<pii>e[N];
vector<int>a;
map<int,int>mp;
bool cmp(int x,int y){return idx[x]<idx[y];}
void table_log(){
    for(int i=1;i<=n;i++)lg[i]=log2(i);
}
void dfs0(int x,int fa){
    idx[x]=++tot;
    rth[tot]=x;
    for(auto u:e[x]){
        if(u.first==fa)continue;
        d[u.first]=d[x]+1;
        f[u.first][0]=x;
        w[u.first][0]=u.second;
        for(int i=1;f[f[u.first][i-1]][i-1];i++)f[u.first][i]=f[f[u.first][i-1]][i-1],w[u.first][i]=min(w[u.first][i-1],w[f[u.first][i-1]][i-1]);
        dfs0(u.first,x);
    }
}
int get(int u,int v){
    int ans=1e18;
    //cout<<"?\n";
    if(d[u]<d[v])swap(u,v);
    while(d[u]!=d[v])ans=min(ans,w[u][lg[d[u]-d[v]]]),u=f[u][lg[d[u]-d[v]]];
    return ans;
}
int lca(int u,int v){
    if(d[u]<d[v])swap(u,v);
    while(d[u]!=d[v])u=f[u][lg[d[u]-d[v]]];
    //cout<<"?\n";
    if(u==v)return u;
    int t=lg[d[u]];
    while(f[u][0]!=f[v][0]){
        while(f[u][t]==f[v][t])t--;
        u=f[u][t],v=f[v][t];
    }
    return f[u][0];
}
void build(){
    vector<int>s;
    s.push_back(1);
    e[1].clear();
    for(auto x:a){
        if(x==1)continue;
        //cout<<s.back()<<"\n";
        int la=lca(s.back(),x);
        //cout<<la<<"\n";
        if(la!=s.back()){
            int lst=s.back();
            s.pop_back();
            while(s.size()&&idx[la]<idx[s.back()]){
                e[s.back()].push_back({lst,get(lst,s.back())});
                lst=s.back();s.pop_back();
            }//cout<<"?\n";
            if(idx[la]==idx[s.back()]){
                e[s.back()].push_back({lst,get(lst,s.back())});
            }else{
                e[la].clear();
                e[la].push_back({lst,get(lst,la)});
                s.push_back(la);
            }
        }
        e[x].clear();
        s.push_back(x);
    }
    int lst=s.back();
    s.pop_back();
    while(s.size())e[s.back()].push_back({lst,get(lst,s.back())}),lst=s.back(),s.pop_back();
}
int DP(int x){
    int dp=0;
    for(auto u:e[x]){
        if(mp.count(u.first))dp+=u.second;
        else dp+=min(u.second,DP(u.first));
    }
    return dp;
}
void solve(){
    cin>>n;d[1]=1;
    for(int i=1,u,v,w;i<n;i++){
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }    
    table_log();
    dfs0(1,0);
    int q;
    cin>>q;
    while(q--){
        int k;
        cin>>k;
        a.clear();mp.clear();
        for(int i=1,z;i<=k;i++)cin>>z,a.push_back(z),mp[z]=1;
        sort(a.begin(),a.end(),cmp);
        //for(auto u:a)cout<<idx[u]<<" ";
        //cout<<"\n";
        build();
        //cout<<"?\n";
        cout<<DP(1)<<"\n";
    }

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--)solve();
}