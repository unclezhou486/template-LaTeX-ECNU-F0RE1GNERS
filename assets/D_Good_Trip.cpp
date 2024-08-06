//https://codeforces.com/problemset/problem/1925/D
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod=1e9+7;

int n,m,k;

long long qmi(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

long long inv(long long x){
    return qmi(x,mod-2);
}

void solve(){
    cin>>n>>m>>k;
    int res=0;
    for(int i=1;i<=m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        res+=w;
        res%=mod;
    }
    int num=n*(n-1)/2;
    num%=mod;
    int a,b;
    a=k;
    b=1;
    int res1=1;
    int fenmu=qmi(num,k);
    int fenzi=qmi(num-1,k);
    if(num==1) fenzi=1;
    int res3=0;
    int ans=(k*res%mod)*inv(num)%mod;
    if(!res) {cout<<ans<<'\n';return;}
    for(int i=1;i<=k;i++){
        res1=((res1*a)%mod)*inv(b)%mod;
        a--;b++;
        //if(num-1)res2*=inv(num-1);
        //res2%=mod;
        int res2= qmi(inv(num),i);
        res2=res2*qmi((num-1)*inv(num)%mod,k-i)%mod;
        ans=ans+(((res1*res2)%mod)*m%mod)*((i*(i-1)%mod)*inv(2)%mod)%mod;
        //cout<<res1<<' '<<res2<<' '<<ans<<'\n';
        //cout<<(res+(i*i-i)*inv(2))%mod<<'\n';
        //cout<<res1<<' '<<res2<<' '<<ans%mod<<'\n';
        ans%=mod;
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}