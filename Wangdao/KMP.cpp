#include<bits/stdc++.h>
using namespace std;
#define MaxSize 1000
#define ElemType int

vector<int> build_next(string pattern){
    // 寻找字串中相同前后缀的最长长度.
    int len = pattern.size();
    vector<int> next(len,0);
    // 当前相同前后缀的长度
    int prefixLen = 0;
    int i =1;
    // prefixLen 代表 pattern[prefixLen] ~ pattern[i]这个闭区间中的 最长-相同-前后缀-长度
    while(i<len){
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
            // 若为next[prefixLen] 相当于
            prefixLen = next[prefixLen-1];
            }
        }
    }
             for(int j=0;j<next.size();j++){
            printf("%d",next[j]);
         }
        cout<<endl;
    return next;
}

int kmp_search(string str, string pattern){
    vector<int> next = build_next(pattern);
    int i=0,j=0;
    while(i<str.size()){
        // 打印状态
        printf("i = %d,j = %d\n",i,j);
        cout<<str<<endl;
        for(int x = 0;x<i-j;x++) printf(" ");
        cout<<pattern<<endl;
        // 字符匹配
        if(str[i]==pattern[j]){    

        
            i++;
            j++;
        }
        // 若j>0,则至少匹配到了一个字符,当pattern[j]不匹配时,pattern[j-1]必然匹配str[i-1],next[j-1]记录的是当前位置的最长相同前后缀长度
        // 即从开头有next[j-1]个字符与next[j-1]个缀字符相同前缀
        // 移动开头
        else if(j>0) j = next[j-1];
        // 字串第一个字符就失配,则
        else i++;
        // 匹配成功
        if(j==pattern.size()){
            return i-j;
        }
    }
    return -1;
}
// 当J = n时,有n个字符与主串相配
int main(){
    string s1 = "ABABABABCABABCABAB";
    string s2 = "aaaaacaaaaa";
    // 001201234
    cout<<s1<<endl<<s2<<endl;
    int pos = kmp_search(s1,s2);
    cout<<pos<<endl;
}

// aaaaacaaaaa len = 5
// 0 1 2 3 4 0 1 2 3 4 5 
// 当i = 5时,prefixLen = 4,next[prefixLen]  = 4 可能会卡住
// 当i = 5时,prefixLen = 4,next[prefixLen-1]  = 3  不会卡死.
