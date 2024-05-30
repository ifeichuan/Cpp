#include<iostream>
#include<D:\Data\study_Code\Wangdao\ch3\Stack.cpp>
#define ElemType int

typedef struct BTreeNode{
    ElemType data;
    struct BTreeNode *left;
    struct BTreeNode *right;
}BTree;

void preOrder(BTree *BT){//先序遍历递归算法
    if(BT!=NULL){
        printf("%d ",BT->data);
        preOrder(BT->left);
        preOrder(BT->right);       
    }
}

void inOrder(BTree *BT){//中序遍历算法
    if(BT!=NULL){
        inOrder(BT->left);
        printf("%d ",BT->data);
        inOrder(BT->right);
    }
}

void postOrder(BTree *BT){//后序遍历算法
    if(BT!=NULL){
        postOrder(BT->left);
        postOrder(BT->right);
        printf("%d ",BT->data);
    }
}

void LevelOrder(BTree *BT){
    
}

void InitBTree(BTree **PBT){//初始化二叉树
    PBT = NULL;
}

bool emptyBTree(BTree *BT){//判断是否为空
    return BT==NULL;
}

BTree* InsertBTree(BTree *BT,ElemType c1,ElemType c2,ElemType ch){//插入单边结点
    BTree *p1,*p2,*p;
    if(ch!=1&&ch!=2) return NULL;
    if(BT==NULL){//当开始树为空时
            p1 = new BTree;
            p2 = new BTree;
            p1->data = c1;
            p1->left = p1->right = NULL;
            p2->data =c2;
            p2->left = p2->right =  NULL;
            if(ch==1){//设置p1为根结点，根据ch判断c2是左孩子还是右孩子
                p1->left = p2;
            }
            else p1->right = p2;
           
            return p1;
        }   
    else if(BT->data ==c1){//若不为空且当前结点值等于c1,则判断插入方向和是否为空
        if(BT->left == NULL&&ch == 1){
            p2  = new BTree;
            p2->data = c2;
            p2->left = p2->right = NULL;//新分支左右孩子设置为NULL
            BT->left = p2;
            return BT;
            }
        else if(BT->right == NULL&&ch == 2){
            p2 = new BTree;
            p2->data = c2;
            p2->left = p2->right = NULL;
            BT->right = p2;
            return BT;
            }
        else return NULL;
        }
        if(BT->left != NULL){//若不为空且不等于c1,则递归函数,直到等于c1为止
            p = InsertBTree(BT->left,c1,c2,ch);//递归左孩子
            if(p!=NULL) return BT; //返回树根
        }
        if(BT->right != NULL){
            p = InsertBTree(BT->right,c1,c2,ch);//递归右孩子
            if(p!=NULL) return BT;
        }
    return NULL;//若没有结点值等于c1,则返回NULL
}

int DepthBTree(BTree *BT,int height = 0){//求二叉树深度
    if(emptyBTree(BT)) return height;
    height ++;
    height =std:: max(DepthBTree(BT->left,height),DepthBTree(BT->right,height));
    return height;
}

int main(){
    BTree *BTOne;
    InitBTree(&BTOne);
    int c1,c2,ch;
    BTree *test = NULL;
    scanf("%d%d%d",&c1,&c2,&ch);
    while (c1!=0){
        
        BTOne = InsertBTree(BTOne,c1,c2,ch);
        preOrder(BTOne);
        printf("\n先序↑\n");
        scanf("%d%d%d",&c1,&c2,&ch);
    }
    printf("%d",DepthBTree(BTOne));
    
}