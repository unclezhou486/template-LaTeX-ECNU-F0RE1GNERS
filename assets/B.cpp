#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n;
    cin>>n;
    long long bmax=0,bmin=0;
    for(int i=0;i<=77;i++){
        if((n-79*i)%77==0){
            bmax=(n-79*i)/77;
            break;
        }
    }
    for(int i=0;i<=79;i++){
        if((n-77*i)%79==0){
            bmin=i;
        }
    }
    long long ans=(bmax-bmin)/79;
    if(bmax||bmin) ans+=1;
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}