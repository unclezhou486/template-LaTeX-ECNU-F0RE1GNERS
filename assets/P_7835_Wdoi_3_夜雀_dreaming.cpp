#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N=1e3+10;

int n,k;

struct node{
    int t,x,y;
}a[N];

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a[i].t>>a[i].x>>a[i].y;
    }
    int ans=4e18;
    for(int i=1;i<=k;i++){
        for(int j=1;j<i;j++){
            int lm=lcm(a[i].t,a[j].t);
            int resi=lm/a[i].t;
            int resj=lm/a[j].t;
            if((a[i].x+(resi-1)*a[i].y)%n!=(a[j].x+(resj-1)*a[j].y)%n){
                ans=min(ans,lm);
            }
            if((a[i].x+(resi*2-1)*a[i].y)%n!=(a[j].x+(resj*2-1)*a[j].y)%n){
                ans=min(ans,lm*2);
            }
        }
    }
    if(ans==4e18) cout<<"Mystia will cook forever...";
    else cout<<ans-1<<'\n';
}