#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<set>
#include<unordered_map>
#include<deque>
#include<iomanip>
#include<bitset>
#define ll long long
#define int long long
using namespace std;
const int N=2e7+5;
const int M=1e8+5;
const int INF=1e9;
//const int p=998244353;
const int MOD=1e9+7;
const double DARW=0.97;
int z[N],p[N];
void solve(){
  string a,b;
  cin>>a>>b;
  b=" "+b;
  a=" "+a;
  int ansz=b.length(),ansp=0;
  for(int l=1,r=1,i=2;i<b.length();i++){
    if(i<=r&&z[i-l+1]<r-i+1)z[i]=z[i-l+1];
    else {
      z[i]=max(0*1ll,r-i+1);
      while(i+z[i]<b.length()&&b[i+z[i]]==b[z[i]+1])z[i]++;
      if(i+z[i]-1>r)r=i+z[i]-1,l=i;
    }
    //cout<<z[i]<<" ";
    ansz^=i*(z[i]+1);
  }
  for(int l=0,r=0,i=1;i<a.length();i++){
    if(i<=r&&z[i-l+1]<r-i+1)p[i]=z[i-l+1];
    else {
      p[i]=max(0*1ll,r-i+1);
      while(i+p[i]<a.length()&&p[i]+1<b.length()&&a[i+p[i]]==b[p[i]+1])p[i]++;
      if(i+p[i]-1>r)r=i+p[i]-1,l=i;
    }
    ansp^=i*(p[i]+1);
  }
  cout<<ansz<<"\n"<<ansp<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	  int t=1,k=1;
	  //cin>>t;
	  while(t--){
      solve();
    }
}