#include <iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
ElemType data;
struct LNode *next;

}LNode, *Linklist;

//链表的初始化
int INitList(Linklist &L){
    L =new LNode;
    L ->next = NULL;
    return 0;
}
//判断链表是否为空
int ListEmpty(Linklist L){
    if(L ->next==NULL)
        return 1;
    return 0;
}
//求单链表的表长
int ListLength(Linklist L){
    int i=0;
    L= L ->next;
    while(L)
    {   i++;
        L =L ->next;
    }
return i;
}
//销毁链表
void DestroyList(Linklist &L){
    LNode *p;
    while(L)
    {
        p=L;
        L=L->next;
        delete p;
    }
}
//清空链表
void ClearList(Linklist &L){
  LNode *p,*q;
  p=L->next;
  while(p)
  {  q=p;
     p=p->next;
     delete q;  
  }
}
//获取元素
int GetElem(Linklist L,int i,ElemType &e){
    LNode *p;
    p=L->next;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    //判断i值是否合法
    if(p==NULL||j>i)
        return -1;
    e=p->data;
    return 0;
}

//查找元素e值，若找到，返回该结点的地址
LNode *LocateElem(Linklist L,ElemType e){
    LNode *p;
    p=L->next;
    while(p&&p->data!=e)
        p=p->next;
    if(!p)
      return NULL;
    else return p;
}
//在第i个位置插入元素e
int ListInsert(Linklist &L,int i,ElemType e){
    //寻找第i-1个结点
    LNode *p;
    p=L->next;int j=1;
    while(p&&j<i-1){
        p=p->next;
        j++;
    }
    //判断i值是否合法
    if(p==NULL||j>i-1)
        return -1;
    LNode *s=new LNode; //生成新结点
    s->data=e;
    s->next=p->next;
    p->next=s;
    return 0;

}
//删除第i个位置的元素
int ListDelete(Linklist &L,int i)
{  LNode *p=L; int j=0;
   //寻找第i-1个结点
   while(p->next&&j<i-1)
   { p=p->next;
     j++;
   }
   //判断i值是否合法
   if(p->next==NULL||j>i-1)
        return -1;
    //需创建指针q指向被删除结点，以便释放其空间
    LNode *q=p->next;
    p->next=q->next;
    delete q;
    return 0;
}
//前插法创建单链表
void CreateList_H(Linklist &L,int n){
    L=new LNode;
    L->next=NULL;
    for(int i=0;i<n;i++)
    { LNode *p=new LNode;
       cin>>p->data;
       p->next=L->next;
       L->next=p;
    }
}
//尾插法创建单链表
void CreateList_R(Linklist &L,int n){
    L=new LNode;
    L->next=NULL;
    LNode *r=L; //r始终指向尾结点
    for(int i=0;i<n;i++)
    { LNode *p=new LNode;
       cin>>p->data;
       p->next=NULL;
       r->next=p;
       r=p;
    } 
}
int main(){
    Linklist L;
    int n=5;
    cout<<"Please input "<<n<<" elements to create a LinkList: ";
    //插入n个元素
    CreateList_R(L,n);
    //输出链表长度，数值上应该为n(n=5)
    cout<<"The length of LinkList is:"<<" "<<ListLength(L)<<endl;
    LNode *p;
    p=L->next;
    cout<<"The elements in the LinkList are: ";
    for(int i=0;i<n;i++)
    { cout<<p->data<<" ";
      p=p->next;
    }
    delete p;
    //获取元素
    ElemType e;
    GetElem(L,3,e);
    cout<<endl<<"The 3rd element is "<<e<<endl;
    //删除第3个元素
    ListDelete(L,3);
    GetElem(L,3,e);
    cout<<"After deleting, the 3rd element is "<<e<<endl;
    //再次打印链表中所有元素来测试一下
    p=L->next;
    for(int i=0;i<n-1;i++)
    { cout<<p->data<<" ";
      p=p->next;
    }
    return 0;
}