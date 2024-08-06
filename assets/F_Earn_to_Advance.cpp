#include <bits/stdc++.h>
#define int long long
#define PIII pair<pair<int,int>,pair<int,int>>
using namespace std;

const int N=81;

int n;
int a[N][N];
int r[N][N],dw[N][N];

//int d[N][N][N][N];
map<tuple<int, int, int, int>,int> d;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    //memset(dp,0x3f,sizeof dp);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            cin>>r[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            cin>>dw[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            //d[i][j][i][j]=0;
            d[{i,j,i,j}]=0;
        }
    }
    //return 0;
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){
            for(int k=n;k>=i;k--){
                for(int l=n;l>=j;l--){
                    if(k==i&&l==j) continue;
                    d[{i,j,k,l}]=1e18;
                    //if(i<n)d[i][j][k][l]=min(d[i][j][k][l],d[i+1][j][k][l]+dw[i][j]);
                    if(i<n&&i+1<=k)d[{i,j,k,l}]=min(d[{i,j,k,l}],d[{i+1,j,k,l}]+dw[i][j]);
                    //if(j<n)d[i][j][k][l]=min(d[i][j][k][l],d[i][j+1][k][l]+r[i][j]);
                    if(j<n&&j+1<=l)d[{i,j,k,l}]=min(d[{i,j,k,l}],d[{i,j+1,k,l}]+r[i][j]);
                }
            }
        }
    }
    //cout<<d[{1,1,1,3}]<<'\n';
    //return 0;
    priority_queue<PIII,vector<PIII >,greater<PIII> >q;
    q.push({{0,0},{1,1}});
    while(q.size()){
        PIII pos=q.top();
        q.pop();
        int t=pos.first.first;
        int v=pos.first.second;
        int x=pos.second.first;
        int y=pos.second.second;
        //cout<<x<<' '<<y<<' '<<t<<'\n';
        if(x==n&&y==n){
            cout<<t<<'\n';
            break;
        }
        for(int i=x;i<=n;i++){
            for(int j=y;j<=n;j++){
                if(i==x&&j==y) continue;
                //int res=d[x][y][i][j];
                int res=d[{x,y,i,j}];
                int ress=(res+v)/a[x][y];
                if((res+v)%a[x][y]){
                    ress+=1;
                }
                q.push({{t+ress+(i-x)+(j-y),v+ress*a[x][y]-res},{i,j}});
            }
        }
    }
    
}