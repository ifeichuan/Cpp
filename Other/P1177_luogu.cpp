#include<iostream>
#include<bits/stdc++.h>

using namespace std;
long long n;
int main(){
    scanf("%lld",&n);
    long long nums[n];
    for(long long i=0;i<n;i++){
        scanf("%lld",&nums[i]);
    }
    sort(nums,nums+n);
    printf("%lld",nums[0]);
    for(long long i=1;i<n;i++){
        printf(" %lld",nums[i]);
    }
    printf("\n");
    int *curee = (int*)(malloc(sizeof(int)*2));
}