#include<bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin>>n;
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    int i=1,j,k;
    while(i!=0){
        cin>>i>>j>>k;
        dp[i][j]=k;
      //  cout<<dp[i][j]<<" ";
    }
    for(i =1;i<=n;i++){
        for(j =1;j<=n;j++){
            dp[i][j] += dp[i-1][j]+dp[i][j-1]-dp[i][j];
        }
    }
    printf("%d",dp[i-1][j-1]);
}