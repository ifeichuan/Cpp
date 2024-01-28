#include<stdio.h>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define maxn 100010
int yanghui[2][maxn],n,p;

int main(){
    scanf("%d",&n);
    n = 1<<n;
    memset(yanghui,0,sizeof(yanghui));
    for(int i =1;i<=n;i++){
        for(int j=n-i;j>=1;j--)
            printf("0 ");
            int k =i%2;
            yanghui[k][i] = 1;
            for(int j = 1;j<i;j++)
                yanghui[k][j]=yanghui[!k][j]+yanghui[!k][j-1];
            for(int j=1;j<=i;j++)
            if(yanghui[k][j]%2) printf("1 ");
            else printf("0 ");
            printf("\n");
            
        }
    }
