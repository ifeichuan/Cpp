#include<bits/stdc++.h>

using namespace std;
int n,m;

int main(){
    
    scanf("%d%d",&n,&m);
    char cells[n][m];
    char t;
    memset(cells,0,sizeof(cells));
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;){
            scanf("%c",&t);
            if(t=='\n') continue;;
            cells[i][j++] = t;
            
        }
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(cells[i][j]!='*')
            {
                    int count = 0;
    if(i+1<n&&j+1<m){
        if(cells[i+1][j+1]=='*') count++;
    }
    if(i-1>=0&&j-1>=0){
        if(cells[i-1][j-1]=='*') count++;
    }
    if(i>=0&&j+1<m){
        if(cells[i][j+1]=='*') count++;
    }
    if(i>=0&&j-1>=0){
        if(cells[i][j-1]=='*') count++;
    }
    if(i+1<n&&j>=0){
        if(cells[i+1][j]=='*') count++;
    }
    if(i-1>=0&&j>=0){
        if(cells[i-1][j]=='*') count++;
    }
    if(i-1>=0&&j+1<m){
        if(cells[i-1][j+1]=='*') count++;
    }
    if(i+1<=n&&j-1>=0){
        if(cells[i+1][j-1]=='*') count++;
    }
    cells[i][j] = count+'0';
            }
            printf("%c",cells[i][j]);
        }
        printf("\n");
    }
    }
