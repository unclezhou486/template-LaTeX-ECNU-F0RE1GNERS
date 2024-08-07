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
#include<functional>
#include<bits/stdc++.h>
#define ll long long
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=3e5+5;
const int M=5e6+5;
const int INF=1e9;
//const int p=998244353;
const int MOD=1e9+7;
const double DARW=0.97;
const double eps=1e-12;
int cmp(double x,double y){
  if(x-y>eps)return 1;
  if(x-y<eps)return -1;
  return 0;
}
struct node{
  double x,y;
}a[N];
node getmid(node a,node b){return {(a.x+b.x)/2,(a.y+b.y)/2};}
double dist(node a,node b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
struct circle{node o;double r;}c;
circle getc(node x1,node x2,node x3){
  double a=x1.x-x2.x,b=x1.y-x2.y,c=x1.x-x3.x,d=x1.y-x3.y,e=((x1.x*x1.x-x2.x*x2.x)+(x1.y*x1.y-x2.y*x2.y))/2,f=((x1.x*x1.x-x3.x*x3.x)+(x1.y*x1.y-x3.y*x3.y))/2;
  node o{(d*e-b*f)/(a*d-b*c),(a*f-c*e)/(a*d-b*c)};
  double r=dist(o,x1);
  return {o,r};
}
void solve(){
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
  random_shuffle(a+1,a+n+1);
  c.o=a[1],c.r=0;
  for(int i=1;i<=n;i++){
    if(cmp(dist(a[i],c.o),c.r)==1){
      c.o=a[i],c.r=0;
      for(int j=1;j<=i-1;j++){
        if(cmp(dist(c.o,a[j]),c.r)==1){
          c.o=getmid(a[i],a[j]);
          c.r=dist(c.o,a[j]);
          for(int u=1;u<=j-1;u++){
            if(cmp(dist(c.o,a[u]),c.r)==1){
              c=getc(a[i],a[j],a[u]);
            }
          }
        }
      }
    }
  }
  cout<<fixed<<setprecision(16)<<c.r<<"\n"<<c.o.x<<" "<<c.o.y<<"\n";
} 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	  int t=1,k=1;
	  //cin>>t;
	  while(t--)solve();
}