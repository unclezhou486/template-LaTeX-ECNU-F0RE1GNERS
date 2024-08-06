#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ans+=a[i];
    }
    map<int,int> maa;
    int mxx=0;
    int lenn=0;
    for(int i=1;i<=n;i++){
        maa[a[i]]++;
        if(maa[a[i]]>=2&&a[i]>mxx){
            mxx=a[i];
        }
        a[i]=mxx;
        ans+=a[i];
    }
    map<int,int> ma;
    int mx=0;
    int len=0;
    for(int i=1;i<=n;i++){
        ma[a[i]]++;
        if(ma[a[i]]==2&&a[i]>mx){
            ans+=1ll*(2*n-2*i+len+3)*(len)/2*mx;
            mx=a[i];
            len=1;
        }
        else if(ma[mx]>=2){
            len+=1;
        }
    }
    ans+=1ll*(len+1)*(len)/2*mx;
    cout<<ans<<'\n';
}

int main(){
    freopen("1.in","r",stdin);
    freopen("2.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}