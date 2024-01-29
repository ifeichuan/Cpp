#include<iostream>
#include<bits/stdc++.h>

using namespace std;
#define maxn 100010
int PrimeNumber[maxn];

void  findingPrimeNumbers(int n){
    int i,j,t=1;
    for(i=2;i<n;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                break;
            }
        }
        if(j==i) PrimeNumber[t++] = i;
    }
}

bool IsPrimeNumber(int n){
    int i;
    for(i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
return true;
    }


int main(){
    int n;
    cin >>n;
    findingPrimeNumbers(n);
    PrimeNumber[1] = 2;
    int i,j;
    for(i=1;i<=(n-2)/2;i++){
        int t = i*2+2;
        printf("%d=",t);
        for(j=1;PrimeNumber[j]<t;j++){
            if(IsPrimeNumber(t-PrimeNumber[j])){
                printf("%d+%d\n",PrimeNumber[j],t-PrimeNumber[j]);
                break;
            }
        }
    }
}