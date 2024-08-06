#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    cin>>a[0];
    a[0]+=k*3;
    for(int i=1;i<n;i++){
        cin>>a[i];
        a[i]+=k;
    }
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q1,q2;
    for(int i=1;i<n;i++){
        //q.push();
        if(a[i]<a[0]) q1.push({a[i],0});
        else q2.push({a[i],0});
    }
    int res=k;
    int ans=q2.size();
    while(q2.size()){
        pair<int,int> pos=q2.top();
        int x=pos.first,time=pos.second;
        q2.pop();
        if(res){
            res--;
            x--;
            time+=1;
            if(x>a[0]) q2.push({x,time});
            else ans--;
            continue;
        }
        if(!q1.size()) break;
        pair<int,int> ver=q1.top();
        int y=ver.first,tim=ver.second;
        q1.pop();
        x--,time+=1;
        y+=2;
        tim+=1;
        if(y>a[0]) break;
        if(tim<k) q1.push({y,tim});
        if(x>a[0]&&time<k) q2.push({x,time});
        if(x<=a[0]){
            ans--;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}