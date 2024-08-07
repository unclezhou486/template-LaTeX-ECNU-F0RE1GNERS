#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
  int date;
  Node *next;
  Node(const int& d):date(d),next(0){}
};

bool cmp1(int a,int b){return a<b;}
class List{
  Node *first,*last;
  unsigned listSize;
public:
  List():first(0),last(0),listSize(0){}
  List(int a[],int num);
  List(const List &a);
  unsigned size() const{return listSize;}
  bool empty()const{return !listSize;}
  void push_back(const int& x);
  void push_front(const int& x);
  bool pop_back();
  bool pop_front();
  bool remove(const int& x);
  void remove_all(const int& x);
  void clear();
  void insert(Node *pos,const int& x);
  void erase(const int& w);
  void erase(Node *pos);
  void print()const;
  Node* find(const int& x)const;
  List& operator=(const List& a);
  List& operator+=(const List& a);
  friend List operator+(const List& a,const List&b);
  void listsort(bool (*cmp)(int,int)=cmp1);
  ~List();
};
void List::listsort(bool (*cmp)(int,int)){//根据传入函数排序 默认升序
  int *arr=new int[listSize];//用于储存链表数据，方便排序
  Node *p=first;
  for(int i=0;i<listSize;++i,p=p->next)arr[i]=p->date;//存入数组
  sort(arr,arr+listSize,cmp);//排序
  p=first;
  for(int i=0;i<listSize;++i,p=p->next)p->date=arr[i];//更新链表
  delete[] arr;
}
List operator+(const List& a,const List&b){
  List c(a);
  c+=b;
  return c;
}
List& List::operator+=(const List& a){
  for(Node *p=a.first;p;p=p->next){
    Node *now=new Node(p->date);
    last->next=now;
    last=now;
  }
  listSize+=a.listSize;
  return *this;
}
List& List::operator=(const List& a){
  if(this==&a)return *this;
  new(this) List(a);
  return *this;
}
void List::remove_all(const int& x){//移除所有为x的数
  while(remove(x));
}
void List::erase(Node *pos){//移除指针为pos的数
  if(pos==first)pop_front();//若指定为首地址则利用pop_front函数
  else {
    Node *p=first;
    while(p->next!=pos)p=p->next;//找到pos前指针
    p->next=pos->next;
    if(pos==last)last=p;
    delete pos;
    --listSize;
  }
}
void List::erase(const int& w){//移除第x个的数
  if(w>listSize)return;//若w大于链表大小则返回
  if(w==1)pop_front();
  else {
    Node *now=first->next,*before=first;
    for(int i=2;i<=w;i++)before=now,now=now->next;//找到第x数所对应指针和第x-1数所对//应指针
    before->next=now->next;
    if(now==last)last=before;
    delete now;
    --listSize;
  }
}
List::List(int a[],int num){//将数组转换为链表
  listSize=num;
  if(!num){
      first=0;
      last=0;
  }else {
    Node *p=new Node(a[0]);
    first=last=p;
    for(int i=1;i<num;i++){
      p=new Node(a[i]);
      last->next=p;
      last=p;
    }
  }
}
List::List(const List &a){//拷贝
  listSize=a.listSize;
  if(!listSize){
    first=last=0;
    return;
  }
  Node *p=new Node(a.first->date),*now=a.first->next;
  first=last=p;
  for(;now;now=now->next){
    p=new Node(now->date);
    last->next=p;
    last=p;
  }
}
void List::push_back(const int& x){//在链表末添加x
  Node *p=new Node(x);
  if(!listSize)first=last=p;
  else {
    last->next=p;
    last=p;
  }
  ++listSize;
}
void List::push_front(const int& x){//将x置入链表首
  Node *p=new Node(x);
  if(!listSize)first=last=p;
  else {
    p->next=first;
    first=p;
  }
  ++listSize;
}
bool List::pop_back(){//移除链表最后一个数
  if(!listSize)return 0;
  if(listSize==1){
    delete[] first;
    first=last=0;
  }else {
    Node *now=first;
    while(now->next!=last)now=now->next;
    last=now;
    delete now->next;
    now->next=0;
  }
  --listSize;
  return 1;
}
bool List::pop_front(){//移除链表第一个数
  if(!listSize)return 0;
  if(listSize==1){
    delete first;
    first=last=0;
  }else {
    Node *now=first;
    first=first->next;
    delete now;
  }
  --listSize;
  return 1;
}
bool List::remove(const int& x){//移除第一个值为x的数
  Node *now=first,*before=first;
  while(now&&now->date!=x)before=now,now=now->next;//找到第一个值为x的数
  if(now){//若存在值为x的数  不存在则返回0
    if(listSize==1){
      delete now;
      first=last=0;
    }else {
      if(now==first){
        first=first->next;
        delete now;
      }
      else if(now==last){
        last=before;
        delete now;
        last->next=0;
      }
      else{
        before->next=now->next;
        delete now;
      } 
    }
    --listSize;
    return 1;
  }
  return 0;
}
void List::clear(){//清空链表
  this->~List();
  first=last=0;
  listSize=0;
}
void List::insert(Node *pos,const int& x){//在pos后插入x
  Node *p=new Node(x);
  p->next=pos->next;
  pos->next=p;
  if(pos==last)last=p;
  ++listSize;
}
List::~List(){
  for(Node *p=first;first!=0;p=first){
    first=first->next;
    delete p;
  }
}
void List::print()const{
  for(Node* now=first;now;now=now->next)cout<<now->date<<" ";
  cout<<"\n";
}
Node* List::find(const int& x)const{//寻找第一个值为x的数 未找到则返回0
  for(Node* p=first;p;p=p->next)
    if(p->date==x)return p;
  return 0;
}
int main(){
	int n;
	cin>>n;
	List a;
	while(n--){
		int num;
		cin>>num;
		a.push_front(num);
	}
	a.print();
	List b;
	b=a;
	b.print();
	cout<<a.find(1)<<'\n';
	cout<<b.find(1)<<"\n";
}