#include<bits/stdc++.h>

using namespace std;

string mult(string s1,string s2){
    int len1,len2;
    len1 = s1.length();
    len2 = s2.length();
    int c[10001];
    for(int i =len1-1;i>=0;i--)
    for(int j = len2-1;j>=0;j--)
    c[i-j+1]+=s1[j]*s2[i];
    string s;
    for(int i=1;i<len1+len2;i++){
        s = char(c[i]+"0") + s;
    }
    return s;
}

int main(){
    string s1,s2,s;
    cin>>s1>>s2;
    s = mult(s1,s2);
    cout<<s;
}
