#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
#define ElemType int

typedef struct DNode
{
    ElemType data;
    struct DNode *prior,*next;
}DNode, *DLinklist;


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

bool InitDList(DLinklist &L){
    L = new DNode;
    L->next = NULL;
    L->prior =NULL;
    return true;
}

Linklist mergeTwoLists(Linklist &L1,Linklist &L2){
    LNode *l1=L1,*l2=L2,*r;
    Linklist L3 = new LNode;
    r = L3;
    while(l1!=NULL&&l2!=NULL){
        if(l1->data < l2->data){
            r->next = l1;
            l1 = l1->next;
        }
        else{
            r->next = l2;
            l2 = l2->next;
        }
        r=r->next;
    }
    if(l1!=NULL) r->next =  l1;
    if(l2!=NULL) r->next = l2;
    return L3;
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

void ListPrint(Linklist &L){
    LNode *r = L->next;
    while(r!=NULL){ printf("%d ",r->data);
    r = r->next;
    }
    printf("\n");
}

bool P01_DeleteValues(Linklist &L,ElemType x){
    LNode *r=L,*q;
    if(r==NULL)  return false;
    while(r!=NULL){
        if(r->next->data  == x){
                q = r->next;
                r->next = q->next;
                free(q);
        }
        r=r->next;
        
    }
    return true;
}

bool  P02_DeleteMinValue(Linklist &L){//删除最小值
    LNode *r,*minNode;
    r=minNode=L;
    if(L==NULL) return false;
    while(r->next!=NULL&&r!=NULL){
        if(r->next->data<minNode->next->data){
            minNode = r;
        }
        r=r->next;
    }
    r = minNode->next;
    minNode->next = r->next;
    free(r);
    return true;
} 

bool P03_ReverseLinkList(Linklist &L){//原地逆序链表
    //该算法的核心思路是将链表的指针域反转,即创建一个NULL指针,保持在遍历指针后面;
    LNode *r = L->next,*temp,*rev=NULL;
    while(r!=NULL){
        temp = r->next;//保存下一个节点，防止断链
        r->next = rev;//指向前一个节点
        rev = r;//往前移动
        r=temp;//往前移动
    }
    L->next = rev;//让链表头节点的指针域指向最后一个不等于NULL的元素，即rev
    return true;
}

bool P04_DeleteBetweenElements(Linklist &L,ElemType a,ElemType b){//就是第二题改一下
        LNode *r=L,*q;
    if(r==NULL)  return false;
    while(r!=NULL){
        if(r->next->data  >=a&&r->next->data<=b){
                q = r->next;
                r->next = q->next;
                free(q);
        }
        r=r->next;
        
    }
    return true;
}

void P05_PublicNodes(Linklist &L1,Linklist &L2){
    //要想找出公共节点，即两个链表中地址相同的节点，
    //方法1
        // 暴力法
    //方法2
        // 遍历到最后一个节点，判断是否相同 但只能得出有公共节点，但无法找出公共节点起始位置在哪
        // 或者可以两个表都遍历一遍，求出长度，用长的减短的，然后长的先再次遍历Len1-len2个节点，
        // 之后L1，L2同时遍历，找到相同的节点即可。
}

bool P06_SplitLinkList(Linklist &L,Linklist &A,Linklist &B){
    LNode *r=L,*a=A,*b=B;
    b->next = NULL;
    a->next = NULL;
    LNode *s;
    while(r!=NULL){
        a->next  = r->next;
        r = r->next;
        a = a->next;
        s=r->next;
        r->next = b->next;
        b->next  = r;
        r = s;
    }
    a->next = NULL;
    return true;
}

void P07_DeleteDuplicateValues(Linklist &L){//删除重复值
    LNode *s,*r = L->next;
    while(r->next!=NULL){
        s = r->next;
        if(s->data == r->data)  {
            r->next = s->next;
            free(s);
        }
        else{
            r=r->next;
        }
    }
}

Linklist P08_FindDuplicateValues(Linklist &A,Linklist &B){//寻找重复值
    Linklist C = new LNode;
    LNode *a,*b,*c;
    a = A->next;
    b = B->next;
    c = C;
    while(a!=NULL&&b!=NULL){
        if(a->data == b->data ){
            LNode *s = new LNode;
            s->data = a->data;
            c->next = s;
            c= c->next;
            a = a->next;
            b = b->next;
        }
        else if (a->data>b->data)
        {
            b = b->next;
        }
        else{
            a = a->next;
        }
    }
    c->next = NULL;
    return C;
}

void P09_FindingIntersection(Linklist &A,Linklist &B){
        // A = P08_FindDuplicateValues(A,B);
        // P07_DeleteDuplicateValues(A);
        LNode *pa = A->next;
        LNode *pb = B->next;
        LNode *u,*pc = A;
        while (pa&&pb)
        {
            if(pa->data == pb->data){
                pc->next = pa;
                pc = pa;
                pa=pa->next;
                u = pb;
                pb = pb->next;
                free(u);
            }
            else if (pa->data > pb->data)
            {
                u = pa;
                pa = pa->next;
                free(u);
            }
            else{
                u=pb;
                pb = pb->next;
                free(u);
            }
            
        }
        
        while (pa)
        {
            u = pa;
            pa = pa->next;
            free(u);
        }
        while(pb){
            u = pb;
            pb = pb->next;
            free(u);
        }
        pc->next = NULL;
        free(B);
        
}

int main(){
    Linklist L,L1,L2;
    List_EndInsert(L1);
    List_EndInsert(L2);
    Linklist L3;
    P09_FindingIntersection(L1,L2);
    ListPrint(L1);
    // L3= P08_FindDuplicateValues(L1,L2);
    // ListPrint(L3);
    // // P01_DeleteValues(L,3);
    // ListPrint(L);
    // P03_ReverseLinkList(L);
    // P06_SplitLinkList(L,L1,L2);
    // ListPrint(L1);
    // ListPrint(L2);
    // P07_DeleteDuplicateValues(L);
    // ListPrint(L);
}