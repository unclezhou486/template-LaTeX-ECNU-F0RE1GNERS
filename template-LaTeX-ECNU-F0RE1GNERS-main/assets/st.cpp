#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e5+5;
int a[N],f[N][25];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}
void st(int n){
    for(int u=1;u<=n;u++)f[u][0]=a[u];
    for(int i=1;(1<<i)<=n;i++){
        for(int u=1;u+(1<<i)-1<=n;u++){
            f[u][i]=max(f[u][i-1],f[u+(1<<(i-1))][i-1]);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)a[i]=read();
    st(n);
    while(m--){
        int l,r;
        l=read();
        r=read();
        int k=log2(r-l+1);   
        cout<<max(f[l][k],f[r-(1<<k)+1][k])<<"\n";
    }
}