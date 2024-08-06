#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n,x;

int a[N];

queue<int> q[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>x;
    int y=sqrt(2*x)+10;
    int res=0;
    int ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1,r=0;l<=n;l++){
        while(l>r||(r<=n&&res<=x)){
            r++;
            if(r>n) break;
            res+=a[r];
            q[a[r]].push(r);
        }
        int pre=l;
        for(int i=0;i<=y;i++){
            if(q[i].size()==0){
                if(pre<r) ans+=(i*(r-pre));
                break;
            }
            int ne=q[i].front();
            if(ne>pre){
                ans+=i*(ne-pre);
                pre=ne;
            }
        }
        res-=a[l];
        q[a[l]].pop();
    }
    cout<<ans<<'\n';
}