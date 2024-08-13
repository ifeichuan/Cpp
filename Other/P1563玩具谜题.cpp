#include<bits/stdc++.h>

using namespace std;

struct listLink{
    int toward;
    string career;
    struct listLink* next;
};
typedef struct listLink listLink;

void addNode(listLink* node){
    node->next = new listLink;
}


int main(){
    long n,m;
    cin>>n>>m;
    listLink *link;
    for(int i = 0;i<n;i++){
        addNode(link);
        cin>>link->toward>>link->career;
        cout<<link->toward<<" "<<link->career;
        link = link->next;
    }
}