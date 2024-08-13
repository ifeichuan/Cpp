#include<stdio.h>

void quick_sort(long long nums[],long long left,long long right){
    long long c = (left+right)/2,t;
    for(long long i=left,j=right;i<c&&j>c;){
       while(nums[i]<nums[c]&&i<c) i++;
       while(nums[j]>nums[c]&&j>c) j--;
       t = nums[i];
       nums[i] =nums[j];
       nums[j] = t;
    }
           quick_sort(nums,0,c);
       quick_sort(nums,c,right);
}

int main(){
    long long len;
    scanf("%lld",&len);
    long long nums[len];
    for(long long i =0;i<len;i++){
        scanf("%lld",&nums[i]);
    }
    quick_sort(nums,0,len);
    printf("%lld",nums[0]);
    for(long long i =1;i<len;i++){
        printf(" %lld",nums[i]);
    }
    printf("\n");
}
