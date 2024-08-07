#include<bits/stdc++.h>
#define int long long
const int N=2e5+5;
using namespace std;
struct Node{
    Node *ch[2];
    int val,prio;
    int cnt;
    int siz;
    int to_rev=0;
    Node(int val):val(val),cnt(1),siz(1){
        ch[0]=ch[1]=nullptr;
        prio=rand();
    }
    inline int upd_siz(){
        siz=cnt;
        if(ch[0]!=nullptr)siz+=ch[0]->siz;
        if(ch[1]!=nullptr)siz+=ch[1]->siz;
        return siz;
    }
    inline void pushdown(){
        swap(ch[0],ch[1]);
        if(ch[0]!=nullptr)ch[0]->to_rev^=1;
        if(ch[1]!=nullptr)ch[1]->to_rev^=1;
        to_rev=0;
    }
    inline void cheak_tag(){
        if(to_rev)pushdown();
    }
};
struct Seg_treap{
#define siz(_) (_==nullptr?0:_->siz)
    Node* root;
    pair<Node*,Node*>split(Node* cur,int sz){
        if(cur==nullptr)return {nullptr,nullptr};
        cur->cheak_tag();
        if(sz<=siz(cur->ch[0])){
            auto temp=split(cur->ch[0],sz);
            cur->ch[0]=temp.second;
            cur->upd_siz();
            return {temp.first,cur};
        }else{
            auto temp=split(cur->ch[1],sz-siz(cur->ch[0])-1);
            cur->ch[1]=temp.first;
            cur->upd_siz();
            return {cur,temp.second};
        }
    }
    Node* merge(Node* sm,Node* bg){
        if(sm==nullptr&&bg==nullptr)return nullptr;
        if(sm!=nullptr&&bg==nullptr)return sm;
        if(sm==nullptr&&bg!=nullptr)return bg;
        sm->cheak_tag(),bg->cheak_tag();
        if(sm->prio<bg->prio){
            sm->ch[1]=merge(sm->ch[1],bg);
            sm->upd_siz();
            return sm;
        }else{
            bg->ch[0]=merge(sm,bg->ch[0]);
            bg->upd_siz();
            return bg;
        }
    }
    void insert(int val){
        auto temp=split(root,val);
        auto l_tr=split(temp.first,val-1);
        Node* new_node;
        if(l_tr.second==nullptr)new_node=new Node(val);
        Node* l_tr_combined=merge(l_tr.first,l_tr.second==nullptr?new_node:l_tr.second);
        root=merge(l_tr_combined,temp.second);
    }
    void seg_rev(int l,int r){
        auto less=split(root,l-1);
        auto more=split(less.second,r-l+1);
        more.first->to_rev=1;
        root=merge(less.first,merge(more.first,more.second));
    }
    void print(Node* cur){
        if(cur==nullptr)return;
        cur->cheak_tag();
        print(cur->ch[0]);
        cout<<cur->val<<" ";
        print(cur->ch[1]);
    }
};
Seg_treap tr;
void solve(){
    srand(time(0));
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)tr.insert(i);
    while(m--){
        int l,r;
        cin>>l>>r;
        tr.seg_rev(l,r);
    }
    tr.print(tr.root);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1,k=1;
    //cin>>t;
    while(t--)solve();
}