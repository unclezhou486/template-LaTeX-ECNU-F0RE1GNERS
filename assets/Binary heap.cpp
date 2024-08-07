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
const int N=1e6+5;
const int M=1e8+5;
const int INF=1e9;
const int p=998244353;
const double DARW=0.97;
int n,a[N];
void up(int x){
  while(x/2&&a[x]<a[x/2]){
    if(a[x]<a[x/2])swap(a[x],a[x/2]);
    x/=2;
  }
}
void down(int x){
  while(2*x<=n){
    int t=2*x;
    if(t+1<=n&&a[t+1]<a[t])t++;
    if(a[t]>=a[x])break;
    swap(a[t],a[x]);
    x=t;
  }
}
void build(){
  for(int i=n;i>=1;i--)down(i);
}
void solve(){
  int q;
  cin>>q;
  while(q--){
    int op,x;
    cin>>op;
    if(op==1){
      cin>>x;
      a[++n]=x;
      up(n);
    }else if(op==2)cout<<a[1]<<"\n";
    else swap(a[1],a[n]),n--,down(1);
  }

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