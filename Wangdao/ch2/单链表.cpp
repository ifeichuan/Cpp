#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<iostream>
#define ElemType int

typedef struct LNode //定义单链表节点类型
{
    ElemType  data;//数据域
    struct LNode *next;//指针域
}LNode,*Linklist;

bool InitList(Linklist &L){ //带头结点的单链表的初始化
    // L = (LNode*)malloc(sizeof(LNode));
    L = new LNode; //创建头节点
    L->next = NULL;
    return true;
}

bool InitList2(Linklist &L){
    L = NULL;
    return true;

}

int Length(Linklist L){//求表长
    int len = 0;
    LNode *p = L;
    while(p->next!=NULL){
        p=p->next;
        len++;
    }
    return len;
}

LNode *GetElem(Linklist L,int i){//查找结点
    LNode *p = L;
    for(int j = 1;j<i&&p!=NULL;j++){
        p = p->next;
    }
    return p;
}

LNode *GetValue(Linklist L,ElemType e){//查找值，返回值节点
    int i;
    LNode *p = L;
    for(i = 1;p!=NULL;i++){
        if(p->data ==e ){
            return p;
        }
        p=p->next;
    }
    return NULL;
}

bool InsertNode(Linklist &L,int i,ElemType e){//插入
    LNode *p=L;
    LNode *q = new LNode;
    int j;
    for(j=0;j<i-1&&p->next!=NULL;j++){
        p = p->next;
    }
    if(p==NULL) return false;
    q->data = e;
    q->next = p->next;
    p->next = q;
    return true;
}

bool DeleteNode(Linklist &L,int i,ElemType &e){//删除值
    LNode *p=L;
    LNode *s = new LNode;
    int j=0;
    while(j<i-1&&p!=NULL){
        p = p->next ;
        j++;
    }
    if(p==NULL||p->next==NULL) return false;
    s = p->next;
    e = s->data;
    p->next = s->next;
    free(s);
    return true;
}

Linklist List_HeadInsert(Linklist &L){//逆向建立单链表 头插法
    // Head Insert  Next
    LNode *s;
    int x;
    L = new LNode;//创建头节点
    L->next = NULL;
  std::cin>>x;
    while(x!=9999){
        s = new LNode;
        s->data = x;
        s->next = L->next;
        L->next = s;
        std::cin>>x;
    }
    return L;
}

Linklist List_EndInsert(Linklist &L){//尾插法
    //创建两个指针，一个用于创建节点，一个用于定位表尾。 而L头指针不改变位置.
    //不要改变头指针的位置
    int x;
    L = new LNode;
    LNode *s,*r=L;
    scanf("%d",&x);
    while (x!=9999)
    {
        s = new LNode;
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d",&x);
    }
    r->next = NULL;
    return L;
}


int main(){
    Linklist L;
    InitList(L);
    List_EndInsert(L);
}