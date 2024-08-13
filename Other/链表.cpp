#include<bits/stdc++.h>

using namespace std;

struct ListNode{
    int val;
    struct ListNode* next;

};


int main(){
    ListNode* head = new ListNode;
    ListNode* p =head;
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        ListNode* q = new ListNode;
        p->next = q;
        p = p->next;
    }
    p->next = head;      
}