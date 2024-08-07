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
    vector<int> Inv(int n,vector<int> A){
        vector<int> B(n);
        B[0]=ksm(A[0],MOD-2,MOD);
        int deg=1;
        while(deg<(n<<1)){
            deg<<=1;
            vector<int> C=(deg<=n?vector<int>(A.begin(),A.begin()+deg):A);
            init(deg,B.size());
            C.resize(lim);B.resize(lim);
            NTT(C,1);NTT(B,1);
            for(int i=0;i<lim;++i)B[i]=B[i]*(2-1ll*C[i]*B[i]%MOD+MOD)%MOD;
            NTT(B,0);B.resize(deg);
        }
        B.resize(n);
        return B;
    }
}
int n;
void solve(){
    cin>>n;
    vector<int> f(n);
    for(int i=0;i<n;i++)cin>>f[i];
    vector<int> g=Poly::Inv(n,f);
    for(int i=0;i<n;i++)cout<<g[i]<<" \n"[i==n-1];
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}