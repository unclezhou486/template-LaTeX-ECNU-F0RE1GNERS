#include <bits/stdc++.h>

using namespace std;

int dp[100][100][2];
vector<int> sta;

int n,m,k;

int lowbit(int x){
    return x&-x;
}

int count(int x){
    int res=0;
    while(x) res++,x-=lowbit(x);
    return res;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    //cout<<"sta:\n";
    for(int i=0;i<(1<<m);i++){
        if(count(i)<=k){
            int res=(i>>(m-1))&1;
            dp[m][i][res]=1;
            sta.push_back(i);
            //cout<<i<<' '<<res<<'\n';
        }
    }
    for(int i=m+1;i<=n;i++){
        for(auto u:sta){
            int v=u>>1;//
            int v1=v+(1<<(m-1));//
            dp[i][u][0]+=(dp[i-1][v][0]);
            dp[i][u][1]+=(dp[i-1][v][1]);
            if(count(v1)<=k)
            dp[i][u][0]+=dp[i-1][v1][0],dp[i][u][1]+=dp[i-1][v1][1];
        }
    }
    //cout<<"dp:\n";
    int ans=0;
    for(auto i:sta){
        int res=i&1;
        ans+=dp[n][i>>1][res];
        //cout<<"i:"<<i<<' '<<"dp:"<<dp[n][i][0]<<' ';
        //cout<<(count(i>>1)+1<=k)<<' '<<dp[n][(i>>1)+(1<<(m-1))][res]<<'\n';
        if(count(i>>1)+1<=k)ans+=dp[n][(i>>1)+(1<<(m-1))][res];
        cout<<ans<<'\n';
    }
    cout<<ans<<'\n';
    return 0;
}