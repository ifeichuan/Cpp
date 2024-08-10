#include<bits/stdc++.h>
using namespace std;
#define MaxSize 1000
#define ElemType int

vector<int> build_next(string pattern){
    // 寻找字串中相同前后缀的最长长度.
    int len = pattern.size();
    vector<int> next(len,0);
    // 当前共同前后缀的长度
    int prefixLen = 0;
    int i =1;
    while(i<len){
         for(int j=0;j<next.size();j++){
            printf("%d ",next[j]);
         }
        cout<<endl;
        if(pattern[prefixLen]==pattern[i]){
            prefixLen++;
            next[i] = prefixLen;
            i++;
    }
    else{
        // 若prefixLen = 0 则前面没有匹配的共同前后缀,则next[i] = 0
        if(prefixLen==0){
            // 
            next[i] = 0;
            i++;
            }
        else{
            prefixLen = next[prefixLen-1];
            }
        }
    }

    return next;
}

int kmp_search(string str, string pattern){
    vector<int> next = build_next(pattern);
    int i=0,j=0;
    while(i<str.size()){
        // 字符匹配
        if(str[i]==pattern[j]){
            i++;
            j++;
        }
        // 字符失配,根据next跳过字串前面的一些字符.
        else if(j>0) j = next[j-1];
        // 字串第一个字符就失配
        else i++;
        // 匹配成功
        if(j==pattern.size()){
            return i-j;
        }
    }
    return -1;
}

int main(){
    string s1 = "ABABABCAA";
    string s2 = "AABAAF";
    cout<<s2<<endl;
    int pos = kmp_search(s1,s2);
    cout<<pos<<endl;
}

