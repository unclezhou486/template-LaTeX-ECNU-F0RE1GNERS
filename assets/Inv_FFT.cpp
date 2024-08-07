#include<bits/stdc++.h>
#define int long long
using namespace std;
const double PI=acos(-1);
const int N=5e6+5;
const int MOD=998244353;
int ksm(int x,int k){
    int ans=1;
    while(k){
        if(k&1)ans=x*ans%MOD;
        x=x*x%MOD;
        k>>=1;
    }
    return ans;
}
namespace Poly{
    int len,Lim=1,Alen,Blen,rev[N],ans[N];
    struct Complex{
        double r,i;
        Complex(){r=0,i=0;}
        Complex(double real,double imag):r(real),i(imag){}
    };
    inline Complex operator +(Complex A,Complex B){return Complex(A.r+B.r,A.i+B.i);}
    inline Complex operator -(Complex A,Complex B){return Complex(A.r-B.r,A.i-B.i);}
    inline Complex operator *(Complex A,Complex B){return Complex(A.r*B.r-A.i*B.i,A.r*B.i+A.i*B.r);}
    inline void init(int Alen,int Blen){
        while(Lim<=Alen+Blen)Lim<<=1,++len;
        for(int i=0;i<Lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
    }
    inline void FFT(vector<Complex>& a,int type){
        for(int i=0;i<Lim;i++)if(i<rev[i])swap(a[i],a[rev[i]]);
        for(int m=2;m<=Lim;m<<=1){
            Complex wn=Complex(cos(2.0*PI/m),sin(2.0*PI/m));
            for(int i=0;i<Lim;i+=m){
                Complex w=Complex(1,0);
                for(int j=0;j<m/2;j++){
                    Complex t=w*a[i+j+m/2];
                    Complex u=a[i+j];
                    a[i+j]=u+t;
                    a[i+j+m/2]=u-t;
                    w=w*wn;
                }
            }
        }
        if(!type){
            reverse(a.begin()+1,a.end());
            for(int i=0;i<Lim;i++)a[i].r/=Lim;
        }
    }
    inline vector<Complex> mul(vector<Complex> f,vector<Complex> g){
        int lf=f.size(),lg=g.size();
        init(lf,lg);
        f.resize(Lim),g.resize(Lim);
        vector<Complex> h(Lim);
        FFT(f,1);FFT(g,1);
        for(int i=0;i<Lim;i++)h[i]=f[i]*g[i];
        FFT(h,0);
        return h;
    }
    vector<Complex> Inv(int n,vector<Complex> A){
        vector<Complex> B(n);
        B[0].r=ksm(A[0].r,MOD-2,MOD);
        int deg=1;
        while(deg<(n<<1)){
            deg<<=1;
            vector<Complex> C=(deg<=n?vector<Complex>(A.begin(),A.begin()+deg):A);
            init(deg,B.size());
            C.resize(Lim);B.resize(Lim);
            FFT(C,1);FFT(B,1);
            for(int i=0;i<Lim;++i)B[i]=B[i]*(Complex(2,0)-C[i]*B[i]);
            FFT(B,0);B.resize(deg);
        }
        B.resize(n);
        return B;
    }
}
int n;
void solve(){
    cin>>n;
    vector<Poly::Complex>A(n);
    for(int i=0;i<n;i++)cin>>A[i].r;
    vector<Poly::Complex>ans=Poly::Inv(n,A);
    for(int i=0;i<n;i++)cout<<(int)(ans[i].r+0.5)<<" ";

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
}