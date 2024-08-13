#include<bits/stdc++.h>

using namespace std;

int main(){
    long n;
    cin>>n;
    long nums[n+2];
    long length=0;
    for(int i = 2;n>=0;n/=i){
        if(n%i==0) nums[length++] = i;
    }
    int max = 0,linshi;
    for(int i=0;i<length&&length-i>length;i++){
        linshi=0;
        for(j=i;j<length;j++){
            if(nums[j]+1==nums[j+1]){
                linshi++;
            }
            else{
                break;
            }
        }
        max = linshi>max?linshi:max;
    }
}