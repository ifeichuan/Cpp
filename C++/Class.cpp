#include<iostream>

using namespace std;

class Student
{
    public:
        int num;
        char name[100];
        int socre;
        int print()
        {
            cout<<num<<" "<<name<<" "<<socre;
            return 0;
        }
};

int main(){
    Student a;
    cin>>a.name;
    a.num = 1;
    a.socre =  99;
    a.print();
}