#include <bits/stdc++.h>

using namespace std;

const int N=2e6+10;
const int mod=998244353;
int dp[N][2][2];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    s='0'+s;
    dp[0][1][1]=dp[0][1][0]=dp[0][0][1]=dp[0][0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=1;j++){
            for(int k=0;k<=1;k++){
                int q=j?s[i]-'0':1;
                int w=k?s[i]-'0':1;
                for(int a=0;a<=q;a++){
                    for(int b=0;b<=w;b++){
                        if((a|b)==(a^b)){
                            dp[i][j][k]+=dp[i-1][j&&a==q][k&&b==w];
                            dp[i][j][k]%=mod;
                        }
                    }
                }
            }
        }
    }
    cout<<dp[1][1][0]<<' '<<dp[1][0][0]<<' '<<dp[1][0][1]<<' ';
    cout<<dp[n][1][1]<<'\n';
    //for(int i=0;i<n;i++)
}