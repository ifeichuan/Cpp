#include<iostream>

using namespace std;
//11111
void SubSitution(int nums[],int len){
   //置换数组
   for(int i = 0;i<len;i++){
    nums[i] +=nums[len-i-1];
    nums[len-i-1] = nums[i] - nums[len-i-1];
    nums[i] = nums[i] - nums[len-i-1];
   }
}

void PrintfArr(int nums[],int len){
    //打印数组
    for(int i=0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}
void frontInsertion(int nums[],int len,int lenth){
    //前插
    for(int i = 0;i<lenth;i++){
        int t = nums[len-1];
        for(int j = 0;j<len;j++){
            nums[len-1-j] = nums[len-2-j];
        }
        nums[0] = t;
    }
}

void Insertion(int nums[],int len,int lenth){
    //中间插入
    for(int i =0;i<lenth;i++){
        int t = nums[len-1];
        for(int j = 0;j<len/2;j++){
            nums[len-1-j] = nums[len-2-j];
        }
        nums[len/2] = t;
    }
}

int main(){
    printf("请依次输入: 姓名长度,南北方人（1/2/3）,男女(1/2)\n");
    int lenth,direction,gender,len;
    scanf("%d%d%d",&lenth,&direction,&gender);
    //此处数组仅支持456！
    printf("请输入要创建的牌组最大值(4/5/6):");
    int size;
    scanf("%d",&size);
    int nums[size*2];
    for(int i=0;i<size;i++){
        nums[i] = i+1;
        nums[i+size] = i+1;
    }
    len = sizeof(nums)/sizeof(int);
    printf("初始数组:");
    PrintfArr(nums,len);
    frontInsertion(nums,len,lenth);
    printf("姓名插入后:");
    PrintfArr(nums,len);
    Insertion(nums,len,len/2-1);
    printf("插入len/2-1张后:");
    PrintfArr(nums,len);
    int under_butt = nums[len-1];
    len--;
    printf("屁股底下的牌:%d\n",under_butt);
    Insertion(nums,len,direction);
    printf("南北方插入后:");
    PrintfArr(nums,len);
    len-=gender;
    printf("性别剔除后:");
    PrintfArr(nums,len);
    frontInsertion(nums,len,(len==6||len==8||len==5||len==7)?7:gender==2?len-3:len/2);
    printf("%d张置换后:",(len==6||len==8||len==5||len==7)?7:gender==2?len-3:len/2);
    PrintfArr(nums,len);
    for(;len>0;){
        frontInsertion(nums,len--,1);
        PrintfArr(nums,len);
    }
    printf("最终结果:屁股底下:%d,最后一张:%d",under_butt,nums[0]);
}