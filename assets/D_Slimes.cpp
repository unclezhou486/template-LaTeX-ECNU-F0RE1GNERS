#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5+10;

int n;
int a[N];
int ans[N];
bool v[N];
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) ans[i]=1e18,v[i]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    priority_queue<int,vector<int>,greater<int> > qq;
    int res=0,ress=0;
    for(int i=1;i<=n;i++){
        while(q.size()&&q.top().first+res<=a[i]){
            v[i-(q.top().second+ress)]=1;
            q.pop();
        }
        while(qq.size()&&v[i-(qq.top()+ress)]){
            qq.pop();
        }
        if(qq.size()){
            ans[i]=min(ans[i],qq.top()+ress);
        }
        res+=a[i];
        ress++;
        q.push({a[i]-res,1-ress});
        qq.push(1-ress);
    }
    while(q.size()) q.pop();
    while(qq.size()) qq.pop();
    for(int i=1;i<=n;i++) v[i]=0;
    //priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    res=0,ress=0;
    for(int i=n;i>=1;i--){
        while(q.size()&&q.top().first+res<=a[i]){
            v[i+q.top().second+ress]=1;
            q.pop();
        }
        while(qq.size()&&v[i+qq.top()+ress]){
            qq.pop();
        }
        if(q.size()){
            ans[i]=min(ans[i],qq.top()+ress);
        }
        res+=a[i];
        ress++;
        q.push({a[i]-res,1-ress});
        qq.push(1-ress);
    }
    for(int i=1;i<=n;i++){
        if(ans[i]==1e18) cout<<-1<<' ';
        else cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}