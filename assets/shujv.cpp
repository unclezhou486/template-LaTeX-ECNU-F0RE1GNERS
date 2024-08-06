#include <bits/stdc++.h>

using namespace std;

const int modn=1e5;

int main(){
    freopen("1.in","w",stdout);
    srand(time(0));
    int t=20000;
    cout<<t<<'\n';
    int res=200000;
    for(int time=1;time<=t;time++){
        if(!res){
            cout<<0<<'\n';
            continue;
        } 
        int n=(rand()%res)+1;
        res-=n;
        cout<<n<<'\n';
        int a[n],b[n];
        for(int i=0;i<n;i++){
            a[i]=(rand()%n)+1;
        }
        for(int i=0;i<n;i++) cout<<a[i]<<' ';
        cout<<'\n';
    }

}