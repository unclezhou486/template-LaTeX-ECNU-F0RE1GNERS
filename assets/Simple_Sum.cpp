#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e7+10;
int t;
int v[N];
int pri[N],cnt;

void shai(){
    for(int i=2;i<N;i++){
        if(!v[i]) {v[i]=i;pri[++cnt]=i;}
        for(int j=1;j<=cnt;j++){
            if(pri[j]>v[i]||pri[j]>N/i) break;
            v[i*pri[j]]=pri[j];
        }
    }
}

void solve(){
    int n;
    int ans=1;
    cin>>n;
    int x=n;
    if(n==1) {cout<<ans<<'\n';return;}
    while(x>1){
        int y=v[x];
        int res=0;
        long long ress=1;
        while(v[x]==y){
            x/=y;
            ress*=y;
            res++;
        }
        if(res==1){
            ans=ans*(y*y-y+1);
        }
        else{
            ans=ans*(ress*ress*y+1)/(y+1);
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    shai();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}