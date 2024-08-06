#include <bits/stdc++.h>

using namespace std;

string s;

//string res;

bool fl1;//len
char ans[30];

char c[70];

int main(){
    for(int i=0;i<26;i++){
        c[i]='A'+i;
    }
    for(int i=26;i<52;i++){
        c[i]='a'+i-26;
    }
    for(int i=52;i<62;i++){
        c[i]='0'+i-52;
    }
    ans[1]='A';
    cout<<ans[1]<<endl;
    int idx=1,d;
    char cc;
    for(int i=1;i<=20;i++){
        cin>>s>>s;
        if(s[0]=='G'){
            return 0;
        }        
        cin>>cc>>d>>s;
        if(d==5){
            idx++;
            ans[idx]='A';
            for(int i=1;i<=idx;i++){
                cout<<ans[i];
            }
            cout<<endl;
        }
        else{
            break;
        }
    }
    int len=idx;idx=1;
    for(int i=1;i<=len;i++){
        int maxn=0;
        char ansc;
        for(int j=0;j<62;j++){
            ans[i]=c[j];
            for(int k=1;k<=len;k++){
                cout<<ans[k];
            }
            cout<<endl;
            cin>>s>>s;
            if(s[0]=='G'){
                return 0;
            }
            cin>>cc>>d>>s;
            if(d>maxn){
                maxn=d;
                ansc=c[j];
            }
        }
        ans[i]=ansc;
    }
    
}