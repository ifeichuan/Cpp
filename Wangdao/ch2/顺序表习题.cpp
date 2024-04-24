#include<stdio.h>
#include<malloc.h>
#define InitSize 50
#define MaxSize 50 //定义最大长度
#define ElemType int //自定义类型

typedef struct{//静态分配结构
    ElemType data[MaxSize];
    int length;
}SqList;

typedef struct{//动态分配结构
    ElemType *data;
    int length,Maxsize;
}SeqList;

void InitList(SqList &L){ //静态分配初始化
    L.length = 0;
}


void TrendsInitList(SeqList &L){//动态分配初始化
    L.data=(ElemType*)malloc(MaxSize*sizeof(ElemType));
    L.length=0;
    L.Maxsize = InitSize;
}

bool InsertList(SeqList &L,int i,ElemType e){//插入
    if(i>L.length+1) return false; //判断范围
    if(L.length>=L.Maxsize) return false;//若大于,则存储空间已满 不能插入
    for(int j = L.length;j>i-1;j--){//第i个位置的下标为i-1
        L.data[j] =L.data[j-1];
    }
    L.data[i-1] = e;//插入e
    L.length++;//长度+1
    return true;
}

bool DeleteList(SeqList &L,int i,ElemType &e){//删除
      if(i>L.length+1) return false;//判断范围
        e = L.data[i-1];
        for(int j  =i-1;j<L.length-1;j++)
            L.data[j] = L.data[j+1];
        L.length--;//长度-1
        return true;
}

int LocateElem(SeqList &L,ElemType e){//查找
    int i;
    for(int i =0;i<L.length;i++){
        if(L.data[i]==e) return i+1;
    }
    return 0;//表示失败
}


///////////////////////////////////////
bool P01_DeleteMinElement(SeqList &L,ElemType &e){//删除最小值
    if(L.length==0) return false;
    int i;
    int  min = 0;//假设最小值为一号元素
    for(i = 1;i<L.length;i++){
        if(L.data[i]<L.data[min]) min =i;
    }
    e = L.data[min];
    L.data[min] = L.data[L.length-1];
    L.length--;
    return true;
}

void P02_ReverseList(SeqList &L){
    ElemType t;
    int i;
    for(i=0;i<L.length/2;i++){
        t = L.data[i];
        L.data[i] = L.data[L.length-i-1];
        L.data[L.length-i-1] = t;
    }
}

void P03_DeleteFixedVar(SeqList &L,ElemType x){//删除表中所有等于x的值
    int i,len=0;
    for(i=0;i<L.length;i++){
        if(L.data[i]!=x){
            L.data[len++] = L.data[i];
        }
    }
    L.length=len;//修改长度
}

void P04_DeleteBetweenVar(SeqList &L,ElemType s,ElemType t){
    if(L.length==0) return;
    if(s>t){
        printf("!s>t!");
        return ;
    }
    int i,len=0;
    for(i=0;i<L.length;i++){
        if(!(L.data[i]>=s&&L.data[i]<=t)){
            L.data[len++] =L.data[i];
        }
    }
    L.length = len;
}

void P05_DeleteDuplicateValues(SeqList &L){//删除重复值
    int i,len=0;
    for(i=0;i<L.length-1;i++){
            if(L.data[i]!=L.data[i+1]){
                L.data[len++] = L.data[i];
            }
    }
    L.data[len++] = L.data[L.length-1];
    L.length=len;
}

SeqList P06_MergeOrderedList(SeqList L1,SeqList L2){//合并有序表
    // if(L1.length==0||L2.length==0) return NULL;
    SeqList L3;
    TrendsInitList(L3);
    int i,j,len;
    i = j = len = 0;
    while(i<L1.length&&j<L2.length){
        if(L1.data[i]<L2.data[j]){
            L3.data[len++] = L1.data[i++];
            }
        else{
             L3.data[len++] = L2.data[j++];
            }
        }
    for(;i<L1.length;i++) L3.data[len++] = L1.data[i];
    for(;j<L2.length;j++) L3.data[len++] = L2.data[j];
    L3.length = len;
    return L3;
}

void P07_ReverseOrder(SeqList &L,int m,int n){
    int i,j;
    ElemType t1,t2;
    for(i = 0,j=m;i<m/2;i++){
        t1 = L.data[i];
        L.data[i] = L.data[m-i-1];
        L.data[m-i-1] = t1;
    }
    for(j=m;j<(m+n)/2;j++){
        t2 = L.data[j];
        L.data[j] = L.data[m+n-j-1];
        L.data[m+n-j-1] = t2;
    }
    for(i=0;i<(m+n)/2;i++){
        t1 = L.data[i];
        L.data[i] = L.data[m+n-i-1];
        L.data[m+n-i-1] = t1;
    }
}

void 二分查找

int main(){
    SeqList L1,L2;
    SeqList L3;
    TrendsInitList(L1);
    TrendsInitList(L2);
    int i,t;
    for(i=0;i<12;i++){
       L1.data[L1.length++] = i;
       L2.data[L2.length++] = i;
        // printf("%d ",L1.data[i]);
    }


    //测试07
    // P07_ReverseOrder(L1,5,7);
    // for(i=0;i<12;i++) printf("%d ",L1.data[i]);

    //测试06
    // L3 = P06_MergeOrderedList(L1,L2);
    // for(i=0;i<L3.length;i++){
    //     printf("%d",L3.data[i]);
    // }

}