#include<bits/stdc++.h>

using namespace std;

string add(string str1,string str2){
    string str3;
    int len1,len2;
    len1 = str1.length();
    len2 = str2.length();
    if(len1>len2){//对齐数位
        for(int i =1;i<=len1-len2;i++){
            str2 = "0"+str2;
        }
    }
    else{
        for(int i =1;i<=len2-len1;i++){
            str1 = "0"+str1;
        }
    }
    len1 = str1.length();//更新位数
    // cout<<str1<<endl<<str2;
    int  c=0;
    int temp;
    for(int i = len1-1;i>=0;i--){
            temp = c+str1[i]+str2[i]-96;
            c=temp/10;
            temp%=10;
            str3 = char(temp+'0')+str3;
    }
    if(c!=0) str3=char(c+'0')+str3;//如果c不等于0,代表还有进位
    //将c+'0'转化为字符后拼接进结果字符串
    return str3;
}

int main(){
    string a,b;
    cin>>a>>b;
    // add(a,b);
    cout<<add(a,b)<<endl;
}