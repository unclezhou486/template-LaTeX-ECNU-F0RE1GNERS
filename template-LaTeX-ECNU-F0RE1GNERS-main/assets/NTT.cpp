#include<bits/stdc++.h>
#define ll long long

using namespace std;
const int N=3e6+5;
inline int ksm(int x,int k,int mod){
    int ans=1;
    while(k){
        if(k&1)ans=1ll*ans*x%mod;
        x=1ll*x*x%mod;
        k>>=1;
    }
    return ans;
}
namespace Poly{
    const int MOD=998244353,G=3,INVG=332748118;
    int lim,len,rev[N],invlim;
    inline void init(int l1,int l2){
        lim=1,len=0;
        while(lim<=l1+l2)lim<<=1,len++;
        for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
        invlim=ksm(lim,MOD-2,MOD);
    }
    inline void NTT(vector<int> &f,int type){
        for(int i=0;i<lim;i++)if(i<rev[i])swap(f[i],f[rev[i]]);
        for(int m=2;m<=lim;m<<=1){
            int wn=ksm(type?G:INVG,(MOD-1)/m,MOD);
            for(int i=0;i<lim;i+=m){
                int w=1;
                for(int j=0;j<m/2;j++){
                    int u=f[i+j],v=1ll*w*f[i+j+m/2]%MOD;
                    f[i+j]=(u+v)%MOD,f[i+j+m/2]=(u-v+MOD)%MOD;
                    w=1ll*wn*w%MOD;
                }
            }
        }
        if(!type){
            for(int i=0;i<lim;i++)f[i]=1ll*f[i]*invlim%MOD;
        }
    }
    inline vector<int> mul(vector<int> f,vector<int> g){
        int lf=f.size(),lg=g.size();
        init(lf,lg);
        f.resize(lim),g.resize(lim);
        vector<int> h(lim);
        NTT(f,1);NTT(g,1);
        for(int i=0;i<lim;i++)h[i]=1ll*f[i]*g[i]%MOD;
        NTT(h,0);
        return h;
    }
}
int n,m;
void solve(){
    cin>>n>>m;
    vector<int> f(n+1),g(m+1);
    for(int i=0;i<=n;i++)cin>>f[i];
    for(int i=0;i<=m;i++)cin>>g[i];
    vector<int> h=Poly::mul(f,g);
    for(int i=0;i<=n+m;i++)cout<<h[i]<<" \n"[i==n+m];
}
int main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}