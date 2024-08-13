#include<iostream>
#include<stdio.h>
using namespace std;
#define MaxSize 50
#define ElemType int


typedef struct{
    ElemType data[MaxSize];//存放元素
    int top; //栈顶指针,初始值为-1
}SqStack;

void InitStack(SqStack &S){//初始化栈
    S.top  = -1;
}

bool StackEmpty(SqStack &S){
    if(S.top != -1) return false;
    return true;
}

bool Push(SqStack &S,ElemType x){//进栈
    if(++S.top >= MaxSize){
        S.top--;
        return false;
    }
    else{
        S.data[S.top] = x;
    }
    return true;
    // 另一种方法是,栈顶初始化为0
    // 进栈改为先进后加
    // 出栈改为先减后出
}


bool Pop(SqStack &S,ElemType &x){//出栈
    if(StackEmpty(S)){//判断栈空
        return false;
    }
    else{
        x = S.data[S.top--];
    }
    return true;
}

typedef struct{
    ElemType data[MaxSize];
    int top1;
    int top2;
}SharedStack;

void InitSharedStack(SharedStack &SS){
    SS.top1 = -1;
    SS.top2 = MaxSize;
}

