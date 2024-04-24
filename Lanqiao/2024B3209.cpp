#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long i,j,t=0,w;
    for(i=1;i<=n;i++){
        w=1;
        for(j=i;j>0;j/=10){
            if(w==1){
               
                if(j%2==0) break;
                 w++;
            }
            else if(w==2){
                w = 1;
                if(j%2!=0) break;
            }
        }
        if(!j) t++;
    }
      cout<<t;  
    }
