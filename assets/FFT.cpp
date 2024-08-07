#include<bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const double PI=acos(-1);
const int N=5e6+5;
namespace Poly{
    int len,Lim=1,Alen,Blen,rev[N],ans[N],p;
    void setP(int x){p=x;}
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
    inline vector<int> mul(vector<int> f,vector<int> g){
        int lf=f.size(),lg=g.size();
        vector<Complex>ff(lf);
        vector<Complex>gg(lg);
        for(int i=0;i<lf;i++)ff[i].r=f[i];
        for(int i=0;i<lg;i++)gg[i].r=g[i];
        vector<Complex> hh=mul(ff,gg);
        vector<int> h(lf+lg-1);
        for(int i=0;i<lf+lg-1;i++)h[i]=(int)(hh[i].r+0.5);
        return h;
    }
    inline vector<int> pmul(vector<int> f,vector<int> g){
        int lf=f.size(),lg=g.size();
        init(lf,lg);
        f.resize(Lim),g.resize(Lim);
        vector<Complex> v1(Lim),v2(Lim),v3(Lim),v4(Lim),h1(Lim),h2(Lim),h3(Lim);
        for(int i=0;i<Lim;i++){
            v1[i].r=f[i]>>15;
            v2[i].r=f[i]&((1<<15)-1);
            v3[i].r=g[i]>>15;
            v4[i].r=g[i]&((1<<15)-1);
        }
        FFT(v1,1);FFT(v2,1);FFT(v3,1);FFT(v4,1);
        for(int i=0;i<Lim;i++){
            h1[i]=v1[i]*v3[i];
            h2[i]=v1[i]*v4[i]+v2[i]*v3[i];
            h3[i]=v2[i]*v4[i];
        }
        FFT(h1,0);FFT(h2,0);FFT(h3,0);
        vector<int> h(lf+lg-1);
        for(int i=0,w1,w2,w3;i<lf+lg-1;i++){
            w1=(int)(h1[i].r+0.5)%p;
            w2=(int)(h2[i].r+0.5)%p;
            w3=(int)(h3[i].r+0.5)%p;
            h[i]=(w1*(1<<30)%p+w2*(1<<15)%p+w3)%p;
        }
        return h;
    }
}
int n,m,p;
void solve(){
    cin>>n>>m>>p;
    Poly::setP(p);
    vector<int>A(n+1);
    vector<int>B(m+1);
    for(int i=0;i<=n;i++)cin>>A[i];
    for(int i=0;i<=m;i++)cin>>B[i];
    vector<int>h=Poly::pmul(A,B);
    for(int i=0;i<=n+m;i++)cout<<h[i]<<" ";

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