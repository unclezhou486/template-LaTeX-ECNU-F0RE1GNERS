#pragma GCC O(3)
#include <bits/stdc++.h>

using namespace std;

int unit;

struct node{
    int l,r;
    int id;
    bool operator<(const node &x) const {
        if(l/unit!=x.l/unit) return l<x.l;
        if((l/unit)&1){
            return r<x.r;
        }
        return r>x.r;
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    unit=sqrt(n);
    vector<int> a(n+1);
    vector<node> q(m+1);
    vector<int> ans(m+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>q[i].l>>q[i].r;
        q[i].id=i;
    }
    sort(q.begin()+1,q.end());
    map<int,int> ma;
    priority_queue<int,vector<int>,less<int> > qu;
    auto del = [&] (int x) -> void {
        ma[x]++;
    };
    auto add = [&] (int x) -> void {
        if(ma[x]==0){
            qu.push(x);
        }
        else{
            ma[x]--;
        }
    };
    auto check = [&] () -> int {
        vector<int> vec;
        int res=-1;
        int a1=0,a2=0,a3=0;
        while(qu.size()){
            int x=qu.top();
            qu.pop();
            if(ma[x]){
                ma[x]--;
                continue;
            }
            if(!a1){
                a1=x;
            }
            else{
                if(!a2){
                    a2=x;
                }
                else{
                    if(!a3){
                        a3=x;
                    }
                    else{
                        vec.push_back(a1);
                        a1=a2,a2=a3,a3=x;
                    }
                }
            }
            if(a3){
                if(a2+a3>a1){
                    res=a2+a3+a1;
                    break;
                }
            }
        }
        if(a1) vec.push_back(a1);
        if(a2) vec.push_back(a2);
        if(a3) vec.push_back(a3);
        for(auto x:vec){
            qu.push(x);
        }
        return res;
    };
    for(int i=1;i<=n;i++){
        add(a[i]);
    }
    for(int i=1,l=1,r=0;i<=m;i++){
        while(l>q[i].l) del(a[--l]);
        while(r<q[i].r) del(a[++r]);
        while(l<q[i].l) add(a[l++]);
        while(r>q[i].r) add(a[r--]);
        ans[q[i].id]=check();
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<'\n';
    }

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}