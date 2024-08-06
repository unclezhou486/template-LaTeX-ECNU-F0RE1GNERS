#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+10;
int n;
int xs,ys,xe,ye;
const long double eps=1e-6;

int sgn(long double x){
    return x>eps?1:(x<-eps ? -1:0);
}

struct node{
    int x,y;
}a[N],res;
struct seg{
    node q,w;
    long double jiaoq,jiaow;
    int jw;
}b[N];
long long det(node a,node b){
    return a.x*b.y-b.x*a.y;
}
long long dot(node a,node b){
    return a.x*b.x+a.y*b.y;
}
long double len(node a){
    return sqrt(a.x*a.x+a.y*a.y);
}
long double dott(node a){
    return (long double)dot(a,res)/len(a);
}
bool cmp(seg a,seg b){
    if(a.jiaoq==b.jiaoq){
        return a.jiaow>b.jiaow;
    }
    return a.jiaoq>b.jiaoq;
}

bool cmp1(seg a,seg b){
    if(a.jiaow==b.jiaow){
        return a.jiaoq>b.jiaoq;
    }
    return a.jiaow>b.jiaow;
}

map<long double,int> ma;

int d[N];

int lowbit(int x){
    return x&(-x);
}

void add(int k,int x){
    for(;k<=n;k+=lowbit(k)) d[k]+=x;
}

int query(int x){
    int res=0;
    for(;x;x-=lowbit(x)) res+=d[x];
    return res;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>xs>>ys>>xe>>ye;
    //if(xs>xe) swap(xs,xe),swap(ys,ye);
    res={xe-xs,ye-ys};
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        b[i].q=((node){a[i].x-xs,a[i].y-ys});
        b[i].w=((node){xe-a[i].x,ye-a[i].y});
    }
    vector<seg> v1,v2,v3;
    for(int i=1;i<=n;i++){
        b[i].jiaoq=dott(b[i].q);
        b[i].jiaow=dott(b[i].w);
    }
    for(int i=1;i<=n;i++){
        if(det(b[i].q,res)>0) v1.push_back(b[i]),cout<<"CCF:"<<i<<' '<<det(b[i].q,res)<<'\n';
        else if(det(b[i].q,res)<0) v2.push_back(b[i]),cout<<i<<' '<<det(b[i].q,res)<<'\n';
        else{
            v3.push_back(b[i]);
        }
    }
    sort(v1.begin(),v1.end(),cmp1);
    sort(v2.begin(),v2.end(),cmp1);
    int cnt=1;
	if(v1.size())v1[0].jw=cnt;
	for(int i=1;i<v1.size();i++){
		if(sgn(v1[i].jiaow-v1[i-1].jiaow)==-1) cnt++;
		v1[i].jw=cnt;
	}
	cnt=1;
	if(v2.size())v2[0].jw=cnt;
	for(int i=1;i<v2.size();i++){
		if(sgn(v2[i].jiaow-v2[i-1].jiaow)==-1) cnt++;
		v2[i].jw=cnt;
	}
    //int cnt=0;
    //for(auto& v:v1){
    //    if(!ma[v.jiaow]) cnt++;
    //    v.jw=cnt;
    //    ma[v.jiaow]=1; 
    //}
    //cnt=0;
    //ma.clear();
    //for(auto& v:v2){
    //    if(!ma[v.jiaow]) cnt++;
    //    v.jw=cnt;
    //    ma[v.jiaow]=1; 
    //}
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    int res1=0,res2=0;
    for(auto v:v3){
        if(dot(v.q,res)>0) res1++;
        else res2++;
    }
    int ans=0;
    ans+=res1*(res1-1)/2+res2*(res2-1)/2;
        for(int i=0;i<v1.size();i++){
            cout<<v1[i].q.x<<' '<<v1[i].q.y<<'\n';
        ans+=query(v1[i].jw);
        add(v1[i].jw,1);
    }
    cout<<'\n';
    //for(auto v:v1){
    //    ans+=query(v.jw);
    //    add(v.jw,1);
    //}
    for(int i=1;i<=n;i++){
        d[i]=0;
    }
        for(int i=0;i<v2.size();i++){
        ans+=query(v2[i].jw);
        add(v2[i].jw,1);
    }
    //for(auto v:v2){
    //    ans+=query(v.jw);
    //    add(v.jw,1);
    //}
    cout<<ans<<'\n';

}