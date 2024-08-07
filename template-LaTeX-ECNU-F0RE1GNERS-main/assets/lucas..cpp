#include<iostream>
#define ll long long
using namespace std;
ll ini[100005];
ll apow(ll a,ll b,ll p){
    ll ans=1;a%=p;
    while(b){
        if(b&1)ans=ans*a%p;
        a=a*a%p;
        b>>=1;
    }
    return ans;
}
ll C(ll n,ll m,ll p){
    if(n<m)return 0;
    return ini[n]*apow(ini[m],p-2,p)*apow(ini[n-m],p-2,p)%p;
}
ll lucas(ll n,ll m,ll p){
    return (m==0)?1:lucas(n/p,m/p,p)*C(n%p,m%p,p)%p;
}
void table(int p){
    ini[0]=1;
    ini[1]=1;
    for(int i=2;i<=p;i++)ini[i]=ini[i-1]*i%p;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,p;
        cin>>n>>m>>p;
        table(p);
        cout<<lucas(n+m,m,p)<<"\n";
    }
}