#include<bits/stdc++.h>

using namespace std;
#define MaxSize 1000
#define ElemType int

class Solution {
public:
  bool isnNumber(string token){
    int len = token.size();
    if(len>1) return true;
    if(token[0]!='+'&&token[0]!='*'&&token[0]!='/'&&token[0]!='-'){
      return true;
    }
    return false;
  }
  long long getNumber(string token){
    long long result = 0;
    int isPositive = 1;
    int i = 0;
    printf("len = %d\n",token.size());
    cout<<token<<endl;
    if(token[0]=='-'){
      isPositive = -1;
      i = 1;
      }
    for(;i<token.size();i++){
      long long t = token[i]-'0';
      result = result*10 + t;
    }
    return result*isPositive;
  }
public:
    int evalRPN(vector<string>& tokens) {
      stack<long long> nums;
      for(int i = 0;i<tokens.size();i++){
        if(isnNumber(tokens[i])){
          long long t = getNumber(tokens[i]);
          printf("%d",t);
          nums.push(t);
        }
        else{
          long long a = nums.top();
          nums.pop();
          long long b = nums.top();
          nums.pop();
          if(tokens[i]=="+"){
            nums.push(b+a);
          }
          else if(tokens[i]=="-"){
            nums.push(b-a);
          }
          else if(tokens[i]=="*"){
            nums.push(b*a);
          }
          else{
            nums.push(b/a);
          }
        }
      }
      return nums.top();
    }
};

int main(){
    Solution A ;
    vector<string> tokens{"3","-4","+"};
    long long X  = A.evalRPN(tokens);
    // 一些测试用例
    vector<string> test1 = {"2", "1", "+", "3", "*"};
    vector<string> test2 = {"4", "13", "5", "/", "+"};
    vector<string> test3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    
    cout << "测试用例1结果: " << A.evalRPN(test1) << endl;
    cout << "测试用例2结果: " << A.evalRPN(test2) << endl;
    cout << "测试用例3结果: " << A.evalRPN(test3) << endl;
    printf("x = %lld",X);
}
