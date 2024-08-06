#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1),dp(n+1);
    vector<int> len(n+2);
    for(int i=1;i<=n;i++) len[i]=2e9;
    for(int i=1;i<=n;i++) cin>>a[i];
    int maxn=0;
    for(int i=1;i<=n;i++){
        int l=0,r=i;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(len[mid]<a[i]) l=mid;
            else r=mid-1;
        }
        dp[i]=l+1;
        maxn=max(maxn,dp[i]);
        len[l+1]=min(len[l+1],a[i]);
    }
    for(int i=1;i<=n;i++){
        len[i]=0;
    }
    len[maxn+1]=2e9;
    set<int> se;
    for(int i=n;i>=1;i--){
        if(a[i]<len[dp[i]+1]){
            len[dp[i]]=max(len[dp[i]],a[i]);
            se.insert(i);
        }
    }
    cout<<se.size()<<'\n';
    for(auto x:se){
        cout<<x<<' ';
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}