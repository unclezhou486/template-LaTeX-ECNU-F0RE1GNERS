#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
#include<stack>
#include<queue>
#include<vector>
#define ll long long
const int N=1e5+5;
using namespace std;
int root,tot;
struct splay{
    int ch[2],fa,val,cnt,size;
}a[N];
void maintain(int x){
    a[x].size=a[a[x].ch[0]].size+a[a[x].ch[1]].size+a[x].cnt;
}
bool get(int x){
    return a[a[x].fa].ch[1]==x;
}
void clear(int x){
    a[x].ch[0]=a[x].ch[1]=a[x].fa=a[x].val=a[x].cnt=a[x].size=0;
}
void rotate(int x){
    int y=a[x].fa,z=a[y].fa,chk=get(x);
    a[y].ch[chk]=a[x].ch[chk^1];
    if(a[x].ch[chk^1])a[a[x].ch[chk^1]].fa=y;
    a[y].fa=x;
    a[x].ch[chk^1]=y;
    a[x].fa=z;
    if(z)a[z].ch[y==a[z].ch[1]]=x;
    maintain(y);
    maintain(x);
}
void splay(int x){
    for(int f=a[x].fa;f=a[x].fa,f;rotate(x)){
        if(a[f].fa)rotate(get(x)==get(f)?f:x);
    }
    root=x;
}
void insert(int k){
    if(!root){
        a[++tot].val=k;
        a[tot].cnt++;
        root=tot;
        maintain(root);
        return;
    }
    int cur=root,f=0;
    while(1){
        if(a[cur].val==k){
            a[cur].cnt++;
            maintain(cur);
            maintain(f);
            splay(cur);
            return;
        }
        f=cur;
        cur=a[f].ch[a[f].val<k];
        if(!cur){
            a[++tot].val=k;
            a[tot].cnt++;
            a[tot].fa=f;
            a[f].ch[a[f].val<k]=tot;
            maintain(tot);
            maintain(f);
            splay(tot);
            return;
        }
    }
}
int rnk(int x){
    int res=0,cur=root;
    while(1){
        if(x<a[cur].val)cur=a[cur].ch[0];
        else {
            res+=a[a[cur].ch[0]].size;
            if(x==a[cur].val){
                splay(cur);
                return res+1;
            }
            res+=a[cur].cnt;
            cur=a[cur].ch[1];
        }
    }
}
int kth(int k){
    int cur=root;
    while(1){
        if(a[cur].ch[0]&&k<=a[a[cur].ch[0]].size)cur=a[cur].ch[0];
        else {
            k-=a[a[cur].ch[0]].size+a[cur].cnt;
            if(k<=0){
                splay(cur);
                return a[cur].val;
            }
            cur=a[cur].ch[1];
        }

    }
}
int pre(){
    int cur=a[root].ch[0];
    if(!cur)return cur;
    while(a[cur].ch[1])cur=a[cur].ch[1];
    splay(cur);
    return cur;
}
int nxt(){
    int cur=a[root].ch[1];
    if(!cur)return cur;
    while(a[cur].ch[0])cur=a[cur].ch[0];
    splay(cur);
    return cur;
}
void del(int k){
    rnk(k);
    if(a[root].cnt>1){
        a[root].cnt--;
        maintain(root);
        return;
    }
    if(!a[root].ch[0]&&!a[root].ch[1]){
        clear(root);
        root=0;
        return;
    }
    if(!a[root].ch[0]){
        int cur=root;
        root=a[root].ch[1];
        a[root].fa=0;
        clear(cur);
        return;
    }
    if(!a[root].ch[1]){
        int cur=root;
        root=a[root].ch[0];
        a[root].fa=0;
        clear(cur);
        return;
    }
    int cur=root;
    int x=pre();
    a[a[cur].ch[1]].fa=root;
    a[root].ch[1]=a[cur].ch[1];
    clear(cur);
    maintain(root);
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x,k;
        cin>>x>>k;
        if(x==1){
            insert(k);
        }else if(x==2){
            del(k);
        }else if(x==3){
            cout<<rnk(k)<<"\n";
        }else if(x==4){
            cout<<kth(k)<<"\n";
        }else if(x==5){
            insert(k);
            cout<<a[pre()].val<<"\n";
            del(k);
        }else {
            insert(k);
            cout<<a[nxt()].val<<"\n";
            del(k);
        }
    }
}
