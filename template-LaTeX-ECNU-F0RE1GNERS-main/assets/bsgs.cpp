#include<iostream>
#include<map>
#include<cmath>
#define ll long long
using namespace std;
ll bsgs(ll a,ll b,ll p){
    map<ll,ll>mp;
    ll cur=1,t=sqrt(p)+1,now;
    for(int B=0;B<=t;B++){
        mp[b*cur%p]=B;
        now=cur;
        cur=cur*a%p;
    }
    cur=now;
    for(int A=1;A<=t;A++){
        if(mp[now])return (ll)A*t-mp[now];
        now=now*cur%p;
    }
    return -1;
}
int main(){
    ll p,b,n;
    cin>>p>>b>>n;
    ll ans=bsgs(b,n,p);
    if(ans==-1)cout<<"no solution\n";
    else cout<<ans<<"\n";
}