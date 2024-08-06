#include <bits/stdc++.h>

using namespace std;

int n,m;

vector<int> ne[20];

int dp[(1<<19)][19];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    while(m--){
        int u,v;
        cin>>u>>v;
        ve[u].push_back(v);
        ve[v].push_back(u);
    }
    
}