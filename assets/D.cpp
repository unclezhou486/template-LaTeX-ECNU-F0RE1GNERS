#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;

int n,w[N],p[N],a[N];

vector<vector<int> > ne(N);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ne[a[i]].push_back(i);
    }
    
}