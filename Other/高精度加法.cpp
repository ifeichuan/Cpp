#include<iostream>
#include<map>
#include<string>
using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int>mymap = {
        
    };
    map<int,string>nums;
    string str;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>str>>a>>b;
        
        mymap.insert({a,b});
        nums.insert({a,str});
    }
    cin>>a;
    for(int i =0;i<a;i++){
        cin>>b;
        cout<<nums[ b]<<" "<<mymap[b]<<endl;
    }
}
