#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
const int N=3e6 +5;
ll inv[N];
void exgcd(ll a,ll b,ll &x,ll &y){
    if(!b)x=1,y=0;
    else exgcd(b,a%b,y,x),y-=a/b*x;
}
int main(){
    ll n,p;
    cin>>n>>p;inv[1]=1;
    for(ll i=2;i<=n;i++){
       inv[i]=(((-p/i)*inv[p%i])%p+p)%p;
    }
    for(int i=1;i<=n;i++){
        cout<<inv[i]<<"\n";
    }
}