#include<bits/stdc++.h>

using namespace std;
#define MaxSize 1000
#define ElemType int

    long long minEnd(int n, int x) {
      if(n==1) return x;
        // 严格递增 位运算同步
        // 18 0001 0010
        // 19 0001 0011 Yes
        // 20 0001 0100 No
        // 22 0001 0110 Yes
    bitset<32> number(x);
    long long ans = 0;
    n-=1;
    int zero = 0;
    for(int i = 0;i<number.size()&&n>0;i++){
        cout<<number[i]<<' '<<i<<endl;
        if(number[i]==0){
            ans = i;
                        zero +=1;
            n-=zero;

        }
    }
    cout<<"ans="<<ans<<endl;
    printf("zero = %d\n",zero);
    return x + pow(2,ans);    
    }

int main(){
    int ans = minEnd(3,18);
    cout<<ans;
}
// 18 0001 0010 1
// 19 0001 0011 2
// 22 0001 0110 3 
// 23 0001 0111 4 
// 26 0001 1010 5 


// 4 0100
// 5 0101
// 6 0110
// 7 0111
// 12 1100