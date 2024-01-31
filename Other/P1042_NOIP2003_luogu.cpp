#include<bits/stdc++.h>

using namespace std;
char str[52000];
int main(){
    char t;
    long long count =0;
    while(1){
        scanf("%c",&t);
        if(t=='\n') continue;
        if(t=='E') break;
        str[count++] = t;
    }
    //十一分制
    int W=0,L=0;
    for(int i = 0;i<count;i++){
        if(str[i]=='W') W++;
        else L++;
        if(L+W==11){
            printf("%d:%d\n",W,L);
            W=0;
            L=0;
        }
    }
    printf("%d:%d\n\n",W,L);
    //二十二分制
     W=0,L=0;
    for(int i = 0;i<count;i++){
        if(str[i]=='W') W++;
        else L++;
        if(L+W==21){
            printf("%d:%d\n",W,L);
            W=0;
            L=0;
        }
    }
        printf("%d:%d\n",W,L);
}