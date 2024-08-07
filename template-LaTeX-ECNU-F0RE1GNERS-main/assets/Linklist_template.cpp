#include<bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
	T date;
	Node* next;
	Node(const T& d):date(d),next(0){}
};
template<typename T>
class LinkList{
public:
	Node<T>* pHead;
	LinkList():pHead(0){};
	~LinkList();
	int IsEmpty();
	void Print();
	void Insert(const T& value);
	void deletenode(const T& value);
	Node<T>* find(const T& value);
	LinkList& operator=(const LinkList& a);
};
template<typename T>
LinkList<T>::~LinkList(){
	Node<T>* pNow;
	while(pHead){
		pNow=pHead;
		pHead=pHead->next;
		delete pNow;
	}
}
template<typename T>
int LinkList<T>::IsEmpty(){
	if(pHead)return 0;//首节点存在即非空
	else return 1;
}
template<typename T>
void LinkList<T>::Print(){
	for(Node<T>* pNow=pHead;pNow;pNow=pNow->next){
		cout<<pNow->date<<" ";
	}
	cout<<"\n";
}
template<typename T>
void LinkList<T>::Insert(const T& value){
	Node<T>* p=new Node<T>(value);
	p->next=pHead;
	pHead=p;
}
template<typename T>
void LinkList<T>::deletenode(const T& value){
	Node<T> *pLst=pHead,*pNow=pHead;
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
template<typename T>
Node<T>* LinkList<T>::find(const T& value){
    Node<T> *pNow=pHead;
	while(pNow&&pNow->date!=value)pNow=pNow->next;
    return pNow;
}
template<typename T>
LinkList<T>& LinkList<T>::operator=(const LinkList<T>& a){
    if(this==&a)return *this;//为自身则返回
    this->~LinkList();//释放原来点
	pHead=0;
	if(!a.pHead)return *this;
	pHead=new Node<T>(a.pHead->date);
	pHead->next=0;
	Node<T>* p;
	for(Node<T> *pNow=a.pHead->next,*plst=pHead;pNow;pNow=pNow->next){
		p=new Node<T>(pNow->date);
		plst->next=p;
		p->next=0;
		plst=p;
	}
    return *this;
}
template<typename T>
LinkList<T> Get_same(const LinkList<T>& a,const LinkList<T>& b){
	Node<T> *it1=a.pHead,*it2=b.pHead;
	LinkList<T> c;
	while(it1&&it2){
		if(it1->date==it2->date)c.Insert(it1->date),it1=it1->next,it2=it2->next;
		else if(it1->date>it2->date)it2=it2->next;
		else it1=it1->next;
	}
	return c;
}
int main(){
	LinkList<char> a;
	LinkList<char> b;
	char a1[]{'A','C','D','G','H'},b1[]{'B','C','E','G','H','O'};
	for(int i=4;i>=0;i--)a.Insert(a1[i]);
	for(int i=5;i>=0;i--)b.Insert(b1[i]);
	LinkList<char> c=Get_same(a,b);
	c.Print(); 
}