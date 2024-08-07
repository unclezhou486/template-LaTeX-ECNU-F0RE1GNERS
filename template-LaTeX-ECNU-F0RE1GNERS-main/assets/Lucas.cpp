#include<bits/stdc++.h>

using namespace std;
#define int long long
const int N=2e5+5;
const int MOD=1e6+3;
const int logn=21;
const double PI=3.1415926535897932384626433832795;
int ksm(int x,int b){
	int ans=1;
	while(b){
		if(b&1)ans=ans*x%MOD;
		x=x*x%MOD;
		b>>=1;
	}
	return ans;
}
int exgcd(int a,int b,int& x,int& y){
	if(!b){x=1,y=0;return a;}
	int ret=exgcd(b,a%b,y,x);
	y-=a/b*x; 
	return ret;
}
int Inv(int a,int p){
	int d,x,y;
	d=exgcd(a,p,x,y);
	if(d==1)return (x%p+p)%p;
	return -1;
}
int Cm(int n,int m,int p){
	int a=1,b=1;
	if(m>n)return 0;
	while(m){
		a=(a*n)%p;
		b=(b*m)%p;
		m--;
		n--;
	}
	return a*Inv(b,p)%p;
}
int Lucas(int n,int m,int p){
	if(m==0)return 1;
	return Cm(n%p,m%p,p)*Lucas(n/p,m/p,p)%p;
}
void solve(){
	int n,l,r,sum;
	cin>>n>>l>>r;
	int len=r-l+1;
	//cout<<len<<"\n";
	cout<<(Lucas(len+n,len,MOD)-1+MOD)%MOD<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	solve();
}