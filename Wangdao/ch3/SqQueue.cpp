/*
队列的顺序存储实现
*/
#include<bits/stdc++.h>

using namespace std;
#define MaxSize 1000
#define ElemType int

typedef struct Queue
{
    ElemType data[MaxSize];//用静态数组存放队列元素
    int front,rear;//队头和队尾指针
    //默认front 为0,
}SqQueue;

void InitQueue(SqQueue &Q){
    Q.rear = Q.front = 0;
}

bool QueueisEmpty(SqQueue &Q){//判断队列是否为空
    return Q.front==Q.rear?true:false;
}

bool EnQueue(SqQueue &Q,ElemType x){//入队操作
    if((Q.rear+1)%MaxSize==Q.front) return false;//判断队列是否已满
    //判断队列已满的条件是队尾指针+1是否等于队头指针
    //队尾指针和队头指针在这时不能相等,因为相等是队列为空的判断条件
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear+1)%MaxSize;//队尾指针加1取模
    //循环队列
    return true;
}

bool DeQueue(SqQueue &Q,ElemType &x){//出队操作,并用x返回
    if(QueueisEmpty(Q)) return false;//队空则报错
    x = Q.data[Q.front];
    Q.front =(Q.front+1)%MaxSize;//指针头后移
    return true;
}

bool GetHead(SqQueue Q,ElemType &x){
    if(QueueisEmpty(Q)){
        return false;
    }
    x = Q.data[Q.front];
    return true;
}

void testQueue(){
    SqQueue Q;
    InitQueue(Q);
    QueueisEmpty(Q);
}
int main(){
    
}