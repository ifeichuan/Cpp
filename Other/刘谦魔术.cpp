#include<bits/stdc++.h>

using namespace std;

void SubSitution(int nums[],int len){
   //�û�����
   for(int i = 0;i<len;i++){
    nums[i] +=nums[len-i-1];
    nums[len-i-1] = nums[i] - nums[len-i-1];
    nums[i] = nums[i] - nums[len-i-1];
   }
}

void PrintfArr(int nums[],int len){
    //��ӡ����
    for(int i=0;i<len;i++){
        printf("%d ",nums[i]);
    }
    printf("\n");
}
void frontInsertion(int nums[],int len,int lenth){
    //ǰ��
    for(int i = 0;i<lenth;i++){
        int t = nums[len-1];
        for(int j = 0;j<len;j++){
            nums[len-1-j] = nums[len-2-j];
        }
        nums[0] = t;
    }
}

void Insertion(int nums[],int len,int lenth){
    //�м����
    for(int i =0;i<lenth;i++){
        int t = nums[len-1];
        for(int j = 0;j<len/2;j++){
            nums[len-1-j] = nums[len-2-j];
        }
        nums[len/2] = t;
    }
}

int main(){
    printf("����������: ��������,�ϱ����ˣ�1/2/3��,��Ů(1/2)\n");
    int lenth,direction,gender,len;
    scanf("%d%d%d",&lenth,&direction,&gender);
    //�˴������֧��456��
    printf("������Ҫ�������������ֵ(4/5/6):");
    int size;
    scanf("%d",&size);
    int nums[size*2];
    for(int i=0;i<size;i++){
        nums[i] = i+1;
        nums[i+size] = i+1;
    }
    len = sizeof(nums)/sizeof(int);
    printf("��ʼ����:");
    PrintfArr(nums,len);
    frontInsertion(nums,len,lenth);
    printf("���������:");
    PrintfArr(nums,len);
    Insertion(nums,len,len/2-1);
    printf("����len/2-1�ź�:");
    PrintfArr(nums,len);
    int under_butt = nums[len-1];
    len--;
    printf("ƨ�ɵ��µ���:%d\n",under_butt);
    Insertion(nums,len,direction);
    printf("�ϱ��������:");
    PrintfArr(nums,len);
    len-=gender;
    printf("�Ա��޳���:");
    PrintfArr(nums,len);
    frontInsertion(nums,len,(len==6||len==8||len==5||len==7)?7:gender==2?len-3:len/2);
    printf("%d���û���:",(len==6||len==8||len==5||len==7)?7:gender==2?len-3:len/2);
    PrintfArr(nums,len);
    for(;len>0;){
        frontInsertion(nums,len--,1);
        PrintfArr(nums,len);
    }
    printf("���ս��:ƨ�ɵ���:%d,���һ��:%d",under_butt,nums[0]);
}