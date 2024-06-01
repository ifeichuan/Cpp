/*
队列的链式实现
*/

#include<bits/stdc++.h>

using namespace std;
#define MaxSize 1000
#define ElemType int

class LinkQueue{
    public:
        typedef struct Queue{
            ElemType data;
            struct Queue *next;
        }Queue;

        Queue *front,*rear;
        void InitQueue(void){//带头节点的空队列
            front = rear = new Queue;
            front->next = NULL;
        }
        bool IsEmpty(void){
            if(front==rear){
                return true;
            }
            return false;
        }
        void EnQueue(ElemType x){//带头结点的入队操作
            Queue *s = new Queue;
            s->data = x;
            s->next = NULL;
            rear->next = s;
            rear = s;
        }
        bool DeQueue(ElemType &x){//带头节点的出队操作,并用x返回
            if(IsEmpty()) return false;
            Queue *s = front->next;
            x  = s->data;
            front->next = s->next;
            if(rear==s){//若为最后一个结点出队,则令
                rear = front;
            }
            free(s);
            return true;
        }
        void NotHead_InitQueue(void){//不带头结点的空队列
            front = rear = NULL;
        }
        bool NotHead_IsEmpty(void){//判空
            return front==NULL?true:false;
        }
        void NotHead_EnQueue(ElemType x){//不带头结点的入队操作
            Queue *s = new Queue;
            s->data = x;
            s->next = NULL;
            if(IsEmpty()){
                    front = rear = s;
            }
            else{
                rear->next =s;
                rear = rear->next;
            }
        }
    bool NotHead_DeQueue(ElemType &x){  //不带头节点的出队操作
            if(NotHead_IsEmpty()){
                return false;
            }
            else{
                Queue *s = front;
                x = s->data;
                front = s->next;
                if(rear == s){//若此次是最后一个结点出队
                    rear = front =NULL;
                }
                free(s);
            }
            return true;
        }
        
};

int main(){
    LinkQueue Q1;
    Q1.InitQueue();
    Q1.EnQueue(2);
    Q1.EnQueue(3);
    printf("%d",Q1.IsEmpty()?1:0);
    printf("%d",Q1.rear->data);
    int x;
    Q1.DeQueue(x);
    printf("%d",x);
}