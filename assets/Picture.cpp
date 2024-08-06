#include <bits/stdc++.h>
#define pl tr<<1
#define pr tr<<1|1

using namespace std;

const int N=5e3+10;

int n;

struct segmentTree{
    int l,r;
    long long sum;
}t[N<<4];

struct Line{
    long long l,r,h,flag;
}line[N<<1];

bool operator < (const Line a,const Line b){
    return a.h<b.h;
}

long long x[N<<1];

void pushup(int tr){
    t[tr].sum=(t[pl].sum+t[pr].sum);
}

void build(int l,int r,int tr){
    t[tr].l=l,t[tr].r=r;
    if(l==r)return;
    int mid=(l+r)>>1;
    build(l,mid,pl);
    build(mid+1,r,pr);    
    return;
}

void update(int l,int r,int tr,int k){
    if(l<=x[t[tr].l]&&x[t[tr].r]<=r){
        t[tr].sum=k;
        return;
    }
    int mid=(t[tr].l+t[tr].r)>>1;
    if(l<=x[t[tr].l]) update(l,r,pl,k);
    if(x[t[tr].r]<r) update(l,r,pr,k);
    pushup(tr);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int  i=1;i<=n;i++){
        int x2,y2,x3,y3;
        cin>>x2>>y2>>x3>>y3;
        line[2*i-1]=(Line){x2,x3,y2,1};
        line[2*i]=(Line){x2,x3,y3,0};
        x[2*i-1]=x2;
        x[2*i]=x3;
    }
    n<<=1;
    sort(x+1,x+1+n);
    sort(line+1,line+1+n);
    for(int i=1;i<=n;i++){
        cout<<line[i].l<<' '<<line[i].r<<' '<<line[i].flag<<'\n';
    }
    int m=unique(x+1,x+1+n)-(x+1);
    build(1,m,1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        update(line[i].l,line[i].l,1,line[i].flag);
        cout<<t[1].sum<<'\n';
        update(line[i].r,line[i].r,1,line[i].flag);
        cout<<t[1].sum<<' '<<line[i+1].h-line[i].h<<'\n';
        ans+=t[1].sum*(line[i+1].h-line[i].h);
    }
    cout<<ans<<'\n';
}