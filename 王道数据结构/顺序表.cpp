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
}//


int main(){

}