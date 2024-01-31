#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,t,max=1,count=0;
    scanf("%d",&n);
    int nums[1003];
    memset(nums,0,sizeof(nums));
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(nums[t]==0){ nums[t]++;count++;}
    }
    printf("%d\n",count);
    for(int i=0;i<1003&&count>=0;i++){
        if(nums[i]) {printf("%d ",i);count--;}
    }
}