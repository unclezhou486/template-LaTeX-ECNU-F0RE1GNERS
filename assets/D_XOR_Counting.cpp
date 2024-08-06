#include <bits/stdc++.h>


using namespace std;

const int mod=998244353;

map<long long ,long long > cnt,sum;

long long dfs(long long x){
    if(cnt[x]) return sum[x]%mod;
    if(x%2){
        dfs(x/2);
        cnt[x]=cnt[x/2];
        sum[x]=sum[x/2]*2+cnt[x/2];
        sum[x]%=mod;
    } 
    else{
        dfs(x/2),dfs(x/2-1);
        cnt[x]=cnt[x/2]+cnt[x/2-1];
        sum[x]=(sum[x/2]+sum[x/2-1])*2;
        sum[x]%=mod;
    }
    return sum[x];
}

void solve(){
    long long n,m;
    cin>>n>>m;
    long long ans=0;
    if(m==1){
        ans=n;
        //cout<<n<<'\n';
    }
    else if(m>=3){
        if(n%2){
            ans=(n+1)/2;
            ans%=mod;
            ans*=ans;
            ans%=mod;
        }
        else{
            ans=n/2;
            ans%=mod;
            ans=ans*(ans+1)%mod;
        }
    }
    else{
        ans=dfs(n);
    }
    cout<<ans%mod<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    cnt[0]=1;
    sum[0]=0;
    while(t--){
        solve();
    }
    return 0;
}