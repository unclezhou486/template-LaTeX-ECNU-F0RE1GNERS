#include <bits/stdc++.h>

using namespace std;

const int N=1e3+10;

int n,m;
int a[N][N];
bool v[N][N];
int s[N][N];

int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
int ansb,ansp;

int ax[24]={3,3,4,4,4,4,5,5,5,5,6,6,3,3,4,4,4,4,5,5,5,5,6,6};
int ay[24]={4,5,3,4,5,6,3,4,5,6,4,5,11,12,10,11,12,13,10,11,12,13,11,12};
int bx[12]={7,7,8,8,8,8,9,9,9,9,10,10};
int by[12]={4,5,3,4,5,6,3,4,5,6,4,5};

bool checkk(int x,int y){
    if(x<1||x>n||y<1||y>m) return 0;
    else return 1;
}

int sol(int xx,int yy,int x,int y){
    return s[xx][yy]-s[x-1][yy]-s[xx][y-1]+s[x-1][y-1];
}

int check(int x,int y){
    if(checkk(x+16,y+9)){
        int x3=x+16;
        int y3=y+9;
        int x4=x,y4=y;
        //x4=x+x2-x3,y4=y+y2-y3;
        if(sol(x3,y3,x4,y4)!=146) return 0;
        bool fl=1;
        for(int i=0;i<24;i++){
            if(a[x+ay[i]][y+ax[i]]) {fl=0;break;}
        }
        if(fl) return 1;
    }
    if(checkk(x+9,y+16)){
        int x3=x+9;
        int y3=y+16;
        int x4=x,y4=y;
        //x4=x+x2-x3,y4=y+y2-y3;
        if(sol(x3,y3,x4,y4)!=146) return 0;
        bool fl=1;
        for(int i=0;i<24;i++){
            //cout<<i<<' ';
            //cout<<x+ax[i]<<' '<<y+ay[i]<<'\n';
            if(a[x+ax[i]][y+ay[i]]) {fl=0;break;}
        }
        if(fl) return 2;
    }
    return 0;
}

void cover(int x,int y,int fl){
    int x2=x+16;
    int y2=y+9;
    if(fl==2) x2=x+9,y2=y+16;
    for(int i=x;i!=x2;i++){
        for(int j=y;j!=y2;j++){
            v[i][j]=1;
        }
    }
}

bool check1(int x,int y,int dxx,int dyy){
    int xx=x+dxx*13,yy=y+dyy*9;
    if(!checkk(xx,yy)) return 0;
    int xxx=x+dxx*3,yyy=y+dyy*2;
    if(sol(max(xxx,x),max(yyy,y),min(xxx,x),min(yyy,y))!=12) return 0;
    if(sol(max(xxx+dxx,xx),max(y,yy),min(xxx+dxx,xx),min(y,yy))!=88) return 0;
    for(int i=0;i<12;i++){
        if(a[x+dxx*bx[i]][y+dyy*by[i]]) return 0;
    }
    return 1;
}

void cover1(int x,int y,int dxx,int dyy){
    int xx=x+dxx*13,yy=y+dyy*9;
    int xxx=x+dxx*3,yyy=y+dyy*2;
    for(int i=x;i!=xxx;i+=dxx){
        for(int j=y;j!=yyy;j+=dyy){
            v[i][j]=1;
        }
    }
    for(int i=xxx+dxx;i!=xx;i+=dxx){
        for(int j=y;j!=yy;j+=dyy){
            v[i][j]=1;
        }
    }
}

bool check2(int x,int y,int dxx,int dyy){
    int xx=x+dxx*9,yy=y+dyy*13;
    if(!checkk(x+dxx*9,y+dyy*13)) return 0;
    int xxx=x+dxx*2,yyy=y+dyy*3;
    if(sol(max(xxx,x),max(yyy,y),min(xxx,x),min(yyy,y))!=12) return 0;
    if(sol(max(xx,x),max(yyy+dyy,yy),min(xx,x),min(yyy+dyy,yy))!=88) return 0;
    for(int i=0;i<12;i++){
        if(a[x+dxx*by[i]][y+dyy*bx[i]]) return 0;
    }
    return 1;
}

void cover2(int x,int y,int dxx,int dyy){
    int xx=x+dxx*9,yy=y+dyy*13;
    int xxx=x+dxx*2,yyy=y+dyy*3;
    for(int i=x;i!=xxx;i+=dxx){
        for(int j=y;j!=yyy;j+=dyy){
            v[i][j]=1;
        }
    }
    for(int i=x;i!=xx;i+=dxx){
        for(int j=yyy+dyy;j!=yy;j+=dyy){
            v[i][j]=1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            if(c=='#') a[i][j]=1;
            else a[i][j]=0;
            s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(v[i][j]) continue;
            int x=check(i,j);
            if(x){
                cover(i,j,x);
                ansb++;
                break;
            }
            if(v[i][j]) continue;
            for(int k=0;k<4;k++){
                bool fl=check1(i,j,dx[k],dy[k]);
                if(fl){
                    cover1(i,j,dx[k],dy[k]);
                    ansp++;
                    break;
                }
            }
            if(v[i][j]) continue;
            for(int k=0;k<4;k++){
                bool fl=check2(i,j,dx[k],dy[k]);
                if(fl){
                    cover2(i,j,dx[k],dy[k]);
                    ansp++;
                    break;
                }
            }
        }
    }
    cout<<ansb<<" "<<ansp<<'\n';
}