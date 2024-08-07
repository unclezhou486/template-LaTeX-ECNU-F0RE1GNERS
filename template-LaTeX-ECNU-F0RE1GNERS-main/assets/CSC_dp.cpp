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
const int N=5e5+5;
const int M=5e6+5;
const int INF=1e9;
//const int p=998244353;
const int MOD=1e9+7;
const double DARW=0.97;
const double eps=1e-12;
int dp[N],a[20];
int gcd(int a,int b){
    if(!b)return a;
    return gcd(b,a%b);
}
void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<a[1];i++)dp[i]=2e18;
    dp[0]=0;
    for(int i=2;i<=n;i++){
        for(int j=0,lim=gcd(a[i],a[1]);j<lim;j++){
            for(int u=j,c=0;c<2;c+=(u==j)){
                int p=(u+a[i])%a[1];
                dp[p]=min(dp[p],dp[u]+a[i]);
                u=p;
            }
        }
    }
    int ans=0;
    for(int i=0;i<a[1];i++){
        if(r>=dp[i])ans+=(r-dp[i])/a[1]+1;
        if(l>dp[i])ans-=(l-1-dp[i])/a[1]+1;
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1,k=1;
	//cin>>t;
	while(t--)solve();
}