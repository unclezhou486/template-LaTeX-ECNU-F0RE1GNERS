#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e3+10;

struct node{
    int l,r,w;
}a[N];
int s[N];
int dp[N];

bool cmp(node a,node b){
    return a.r<b.r;
}

bool check(int x,int ll){
    if(a[x].r>=ll) return 1;
    else return 0;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i].l>>a[i].r>>a[i].w;
        if(a[i].l>a[i].r) swap(a[i].l,a[i].r);
    }
    sort(a+1,a+1+m,cmp);
    for(int i=1;i<=m;i++){
        s[i]=s[i-1]+a[i].w;
    }
    a[0].l=0;
    a[0].r=0;
    dp[0]=0;
    int ans=1e18;
    for(int i=1;i<=m;i++){
        dp[i]=1e18;
        for(int j=0;j<i;j++){
            if(a[j].r<a[i].l||(a[j].l>a[i].l&&a[j].r<a[i].r)){
                int l=0,r=j;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(check(mid,a[j].l)) r=mid;
                    else l=mid+1;
                }
                dp[i]=min(dp[i],dp[j]+s[i-1]-s[l]);
            }
        }
        ans=min(ans,dp[i]+s[m]-s[i]);
    }
    cout<<ans<<'\n';
}