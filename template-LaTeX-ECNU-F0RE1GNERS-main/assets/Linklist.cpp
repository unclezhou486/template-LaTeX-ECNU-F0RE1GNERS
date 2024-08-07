#include<bits/stdc++.h>
using namespace std;
struct Node{
	int date;
	Node* next;
	Node(const int& d):date(d),next(0){}
};
class LinkList{
	Node* pHead;
public:
	LinkList():pHead(0){};
	~LinkList();
	int IsEmpty();
	void Print();
	void Insert(int value);
	void deletenode(int value);
	Node* find(int value);
	LinkList& operator=(const LinkList& a);
};
LinkList::~LinkList(){
	Node* pNow;
	while(pHead){
		pNow=pHead;
		pHead=pHead->next;
		delete pNow;
	}
}
int LinkList::IsEmpty(){
	if(pHead)return 0;//首节点存在即非空
	else return 1;
}
void LinkList::Print(){
	for(Node* pNow=pHead;pNow;pNow=pNow->next){
		cout<<pNow->date<<" ";
	}
	cout<<"\n";
}
void LinkList::Insert(int value){
	Node* p=new Node(value);
	p->next=pHead;
	pHead=p;
}
void LinkList::deletenode(int value){
	Node *pLst=pHead,*pNow=pHead;
	while(pNow&&pNow->date!=value)pLst=pNow,pNow=pNow->next;
    if(!pNow)return;//不存在value
    if(pNow==pHead){//删除节点为首节点
        pHead=pHead->next;
        delete pNow;
    }else {//删除节点非首节点
        pLst->next=pNow->next;
        delete pNow;
    }
}
Node* LinkList::find(int value){
    Node *pNow=pHead;
	while(pNow&&pNow->date!=value)pNow=pNow->next;
    return pNow;
}
LinkList& LinkList::operator=(const LinkList& a){
    if(this==&a)return *this;//为自身则返回
    this->~LinkList();//释放原来点
	pHead=0;
	if(!a.pHead)return *this;
	pHead=new Node(a.pHead->date);
	pHead->next=0;
	Node* p;
	for(Node *pNow=a.pHead->next,*plst=pHead;pNow;pNow=pNow->next){
		p=new Node(pNow->date);
		plst->next=p;
		p->next=0;
		plst=p;
	}
    return *this;
}
int main(){
	LinkList a;
    int num,n;
	cout<<"the size of list:";
	cin>>n;
	while(n--){//测试输入
		cout<<"cin:";
		cin>>num;
		a.Insert(num);
		cout<<"list a:";
		a.Print();
	}
	LinkList b;
    b=a;
	cout<<"list b:";
	b.Print();
	int finda;
	cout<<"find:";
	cin>>finda;
	Node* it=a.find(finda);//测试查找、=
	cout<<"the address of findnum:";
	cout<<it<<"\n";
	it->date=0;
	cout<<"list a:";
	a.Print();
	cout<<"list b:";
	b.Print();
	int del;
	while(!a.IsEmpty()){//测试删除，判空
		cout<<"del:";
		cin>>del;
		a.deletenode(del);
		cout<<"list a:";
		a.Print();
	}
	
}