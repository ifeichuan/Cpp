#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define ElemType int

typedef struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *DLinklist;//注意这个空格！

bool InitDList(DLinklist &L){
    L = new DNode;
    L->next = NULL;
    L->prior =NULL;
    return true;
}


bool InsertDNode(DLinklist &L,int i,ElemType e){//后插法
    DNode *s,*p=L;
    int j=0;
    while(j<i-1&&p->next!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    s = new DNode;
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next= s;
    return true;
}

bool DeleteDNode(DLinklist &L,int i,ElemType &e){//删除节点
    DNode *p=L;
    DNode *s;
    int j =0;
    while(j<i-1&&p->next!=NULL){
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    s = p->next;//指向要删除的节点
    e = s->data;//用e返回元素
    p->next = s->next;//前一个节点的后驱指向下一个节点的后驱
    s->next->prior = p;//下一个节点的前驱指向上一个节点
    free(s);
    return true;
}

int main(){
    DLinklist L;
    InitDList(L);
}