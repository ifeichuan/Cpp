#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m,t;
    scanf("%d %d",&n,&m);
    n=n+1;
    int candidate[n];
    memset(candidate,0,sizeof(candidate));
    for(int i =1;i<m+1;i++){
        scanf("%d",&t);
        candidate[t]++;
    }
    for(int i =1;i<n;i++){
        for(int j =0;j<candidate[i];j++){
            printf("%d ",i);
        }
    }
}