#include<iostream>

using namespace std;

int main(){
    int num;//学号
    char sex;//性别
    double score1,score2,score3;
    cout<<"Please input student's ID、'M' or 'W'、score1,socre2 and score3"<<endl;
    cin>>num>>sex>>score1>>score2>>score3;
    cout<<"ID:"<<num<<" "<<sex<<" Total socre is:"<<score1+score2+score3<<endl;
    bool c;
    return 0;
}