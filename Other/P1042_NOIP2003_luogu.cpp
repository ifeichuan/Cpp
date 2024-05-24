#include<bits/stdc++.h>

using namespace std;

int main(){
    char result[700000];
    int i,j,sc1,sc2;
    for(i=0;cin>>result[i]&&result[i]!='E';i++);
    // cout<<result;
    sc1 = 0;
    sc2 = 0;
    for(i = 0;result[i]!='E';i++){
        if(result[i] =='W') sc1++;
        else sc2++;
        if(abs(sc1-sc2)>=2){
            if(sc1>=11||sc2>=11){
                printf("%d:%d\n",sc1,sc2);
                sc1 = sc2 = 0;
                }
            }    
    }
    
     printf("%d:%d\n",sc1,sc2);
     printf("\n");
     sc1 = sc2 = 0;
    for(i = 0;result[i]!='E';i++){
        if(result[i] =='W') sc1++;
        else sc2++;
        if(abs(sc1-sc2)>=2){
            if(sc1>=21||sc2>=21){
                printf("%d:%d\n",sc1,sc2);
                sc1 = sc2 = 0;
                }
            }    
    }
     printf("%d:%d\n",sc1,sc2);
 }

// W W W W W W W W W W W 
// W W W W W W W W W W W 
// L W
// W W W W W W W W W W W 
// W W W W W W W W W W W
// L W
