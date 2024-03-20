#include<bits/stdc++.h>

using namespace std;

int recursion(int n){
    if(n==1){
        return 1;
    }
    else if(n==2){
        return 2;
    }
    else{
        return recursion(n-1)+recursion(n-2);
    }
}

int main(){
    int a;
    cin>>a;
    if(a==0) cout<<0;
    else{
    cout<<recursion(a);}
}