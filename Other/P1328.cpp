#include<iostream>
using namespace std;

int compare(int a,int b){
    //0 剪刀 1石头 2布 3蜥蜴人 4博世科
    if(a==0&&(b==1||b==4)) return -1;
    if(a==0&&(b==2||b==3)) return 1;

    if(a==1&&(b==2||b==4)) return -1;
    if(a==1&&(b==0||b==3)) return 1;

    if(a==2&&(b==0||b==3)) return -1;
    if(a==2&&(b==1||b==4)) return 1;

    if(a==3&&(b==1||b==0)) return -1;
    if(a==3&&(b==2||b==4)) return 1;

    if(a==4&&(b==2||b==3)) return -1;
    if(a==4&&(b==0||b==1)) return 1;
    return 0;
}


int main(){
    int n,Na,Nb;
    int i,j,k;
    cin>>n>>Na>>Nb;
    int regularA[Na],regularB[Nb];
    for(i=0;i<Na;i++){
        cin>>regularA[i];
    }
    for(i=0;i<Nb;i++){
        cin>>regularB[i];
    }
    int scoreA,scoreB;
    scoreA = 0;
    scoreB = 0;
    j = 0;
    k = 0;
    int t=0;
    for(i=1;i<=n;i++){
                    if(j==Na) j = 0;
            if(k==Nb) k = 0;
            t =  compare(regularA[j++],regularB[k++]);//1代表A得分，-1代表B得分，0代表平局
            if(t==1) scoreA++;
            if(t==-1) scoreB++;


    }
    cout<<scoreA<<" "<<scoreB;
}