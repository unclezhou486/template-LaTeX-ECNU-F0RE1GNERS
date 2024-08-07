#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;

int e[N<<1],ne[N<<1],h[N],idx,w[N<<1];
int d[N];
int nex[N*31][2],root,tot;

void add(int x,int y,int z){e[++idx]=y,ne[idx]=h[x],h[x]=idx;w[idx]=z;}

int newcode(){return tot++;}

void init(){
    tot=1;
    root=newcode();
}

void insert(int x){
    int p=root;
    for(int i=30;~i;i--){
        int t=(x>>i)&1;
        if(!nex[p][t]) nex[p][t]=newcode();
        p=nex[p][t];
    }
}

int query(int x){
    int p=root;
    int res=0;
    for(int i=30;~i;i--){
        int t=(x>>i)&1;
        if(nex[p][t^1]){
            res=res*2+1;
            p=nex[p][t^1];
        }
        else{
            res=res*2;
            p=nex[p][t];
        }
    }
    return res;
}

void dfs(int x,int fa){
    for(int i=h[x];i;i=ne[i]){
        int j=e[i];
        if(j==fa) continue;
        d[j]=d[x]^w[i];
        insert(d[j]);
        dfs(j,x);
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<n;i++){
        int u,v,w;
        cin>>u>>v>>w;
        add(u,v,w),add(v,u,w);
    }
    init();
    d[1]=0;
    insert(0);
    dfs(1,1);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,query(d[i]));
    }
    cout<<ans<<'\n';
}