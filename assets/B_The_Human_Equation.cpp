#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;

void solve(){
    cin>>n;
    int x=0;
    int y;
    vector<int> vec;
   for(int i=1;i<=n;i++){
        cin>>y;
        if(!y) continue;
        if(x*y>=0){
            x+=y;
        }
        else{
            vec.push_back(x);
            x=y;
        }
    }
    if(x) vec.push_back(x);
    //for(auto v:vec){
    //    cout<<v<<' ';
    //}
    //cout<<'\n';
    int m=vec.size();
    if(m==0){
        cout<<0<<'\n';
    }
    else if(m==1){
        cout<<abs(vec[0])<<'\n';
    }
    else if(m==2){
        cout<<max(abs(vec[0]),abs(vec[1]))<<'\n';
        //cout<<abs(abs(vec[0])-abs(vec[1]))<<'\n';
    }
    else{
        priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > q;
        vector<int> l(m+10),r(m+10),val(m+10),vis(m+10);
        for(int i=1;i<=m;i++){
            l[i]=i-1;
            r[i]=i+1;
            val[i]=abs(vec[i-1]);
        }
        l[m+1]=m;r[0]=1;
        for(int i=1;i<=m;i++){
            q.push({abs(vec[i-1],i)});
        }
        int ans=0;
        while(q.size()){
            pair<int,int> pos=q.top();
            q.pop();
            int v=val[id],id=pos.second;
            if(vis[id]) continue;
            vis[id]=1;
            if(v<=ans){
                int ll=l[id],rr=r[id];
                r[ll]=rr;
                l[rr]=ll;
                continue;
            }
            int res=v-ans;
            int ll=l[id],rr=r[id];
            if(ll){
                vis[rr]=1;
                
            }

        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}