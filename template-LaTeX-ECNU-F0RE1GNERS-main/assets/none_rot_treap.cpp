#include<bits/stdc++.h>
#define int long long
const int N=1e5+5;
using namespace std;

struct Node{
    Node *ch[2];
    int val,prio;
    int cnt;
    int siz;
    Node(int val):val(val),cnt(1),siz(1){
        ch[0]=ch[1]=nullptr;
        prio=rand();
    }
    Node(Node *node){
        val=node->val,prio=node->prio,cnt=node->cnt,siz=node->siz;
    }
    inline void upd_siz(){
        siz=cnt;
        if(ch[0]!=nullptr)siz+=ch[0]->siz;
        if(ch[1]!=nullptr)siz+=ch[1]->siz;
    }
};
struct none_rot_treap{
#define _3 second.second
#define _2 second.first
    Node* root;
    pair<Node*,Node*> split(Node* cur,int key){
        if(cur==nullptr)return {nullptr,nullptr};
        if(cur->val<=key){
            auto temp=split(cur->ch[1],key);
            cur->ch[1]=temp.first;
            cur->upd_siz();
            return {cur,temp.second};
        }else{
            auto temp=split(cur->ch[0],key);
            cur->ch[0]=temp.second;
            cur->upd_siz();
            return {temp.first,cur};
        }
    }
    tuple<Node*,Node*,Node*>split_by_rk(Node* cur,int rk){
        if(cur==nullptr)return {nullptr,nullptr,nullptr};
        int ls_siz=cur->ch[0]==nullptr?0:cur->ch[0]->siz;
        if(rk<=ls_siz){
            Node *l,*mid,*r;
            tie(l,mid,r)=split_by_rk(cur->ch[0],rk);
            cur->ch[0]=r;
            cur->upd_siz();
            return {l,mid,cur};
        }else if(rk<=ls_siz+cur->cnt){
            Node *lt=cur->ch[0];
            Node *rt=cur->ch[1];
            cur->ch[0]=cur->ch[1]=nullptr;
            return {lt,cur,rt};
        }else{
            Node *l,*mid,*r;
            tie(l,mid,r)=split_by_rk(cur->ch[1],rk-ls_siz-cur->cnt);
            cur->ch[1]=l;
            cur->upd_siz();
            return {cur,mid,r};
        }
    }
    Node* merge(Node* u,Node* v){
        if(u==nullptr&&v==nullptr)return nullptr;
        if(u!=nullptr&&v==nullptr)return u;
        if(v!=nullptr&&u==nullptr)return v;
        if(u->prio<v->prio){
            u->ch[1]=merge(u->ch[1],v);
            u->upd_siz();
            return u;
        }else{
            v->ch[0]=merge(u,v->ch[0]);
            v->upd_siz();
            return v;
        }
    }
    void insert(int val){
        auto temp=split(root,val);
        auto l_tr=split(temp.first,val-1);
        Node *new_node;
        if(l_tr.second==nullptr){
            new_node=new Node(val);
        }else{
            l_tr.second->cnt++;
            l_tr.second->upd_siz();
        }
        Node *l_tr_combined=merge(l_tr.first,l_tr.second==nullptr?new_node:l_tr.second);
        root=merge(l_tr_combined,temp.second);
    }
    void del(int val){
        auto temp=split(root,val);
        auto l_tr=split(temp.first,val-1);
        if(l_tr.second->cnt>1){
            l_tr.second->cnt--;
            l_tr.second->upd_siz();
            l_tr.first=merge(l_tr.first,l_tr.second);
        }else{
            if(temp.first==l_tr.second){
                temp.first=nullptr;
            }
            delete l_tr.second;
            l_tr.second=nullptr;
        }
        root=merge(l_tr.first,temp.second);
    }
    int qrank_by_val(Node *cur,int val){
        auto temp=split(cur,val-1);
        int ret=(temp.first==nullptr?0:temp.first->siz)+1;
        root=merge(temp.first,temp.second);
        return ret;
    }
    int qval_by_rank(Node *cur,int rk){
        Node *l,*mid,*r;
        tie(l,mid,r)=split_by_rk(cur,rk);
        int ret=mid->val;
        root=merge(merge(l,mid),r);
        return ret;
    }
    int qprev(int val){
        auto temp=split(root,val-1);
        int ret=qval_by_rank(temp.first,temp.first->siz);
        root=merge(temp.first,temp.second);
        return ret;
    }
    int qnex(int val){
        auto temp=split(root,val);
        int ret=qval_by_rank(temp.second,1);
        root=merge(temp.first,temp.second);
        return ret;
    }
};
none_rot_treap tr;
int a[N];
void solve(){
    srand(time(0));
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],tr.insert(a[i]);
    int lst=0;
    while(m--){
        int op,x;
        cin>>op>>x;
        x^=lst;
        if(op==1)tr.insert(x);
        else if(op==2)tr.del(x);
        else if(op==3)ans^=(lst=tr.qrank_by_val(tr.root,x));
        else if(op==4)ans^=(lst=tr.qval_by_rank(tr.root,x));
        else if(op==5)ans^=(lst=tr.qprev(x));
        else ans^=(lst=tr.qnex(x));
    }
    cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1,k=1;
	//cin>>t;
	while(t--){
    	solve();
    }
}