#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct LNode //定义单链表节点类型
{
    int data;//数据域
    struct LNode *next;//指针域
}LNode,*Linklist;

Linklist InitList(){//带头结点的单链表初始化
    Linklist L = (LNode*)malloc(sizeof(LNode));
    L->next =NULL;
    return L;
}

int main(){
    
}