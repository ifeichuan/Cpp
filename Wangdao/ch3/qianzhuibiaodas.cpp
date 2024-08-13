#include<bits/stdc++.h>

using namespace std;
#define MaxSize 1000
#define ElemType int

int evalRPN(vector<string>& tokens) {
      stack<int> s;
      int t,sum = 0,b,flag=1;
      for(int i = 0;i<tokens.size();i++){
        t = 0;
        if(tokens[i][0]!='+'&&tokens[i][0]!='-'&&tokens[i][0]!='*'&&tokens[i][0]!='/'){
          for(int j  =0;j<tokens[i].size();j++){
            t = t*10 + (tokens[i][j]-48);
          }
          s.push(t);
        }
        else{
          if(tokens[i].size()>1){
               t = 0;
              for(int j  =1;j<tokens[i].size();j++){
                t = t*10 + (tokens[i][j]-48);
            }
              s.push(-t);
              continue;
              }
          if(flag){
          sum = s.top();
          s.pop();
          b = s.top();
          s.pop();
          flag = 0;
          }
          else{
            b = s.top();
            s.pop();
          }
          if(tokens[i][0]=='+'){
            s.push(sum+b);
          }
          else if(tokens[i][0]=='-'){
            s.push(sum-b);
          }
          else if(tokens[i][0]=='*') s.push(sum*b);
          else if(tokens[i][0]=='/') s.push(sum/b);
        }
        
      }
      return s.top();
    }

int main(){
    vector<string> s= {"2","1","+","3","3"};
    vector<string> s2= {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    printf("%d",evalRPN(s2));
}