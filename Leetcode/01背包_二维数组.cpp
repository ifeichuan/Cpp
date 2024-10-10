#include<iostream>
#include<vector>
using namespace std;

int main(){
    int M,baseWeight;
    cin>>M>>baseWeight;
    vector<int> weight(M,0);
    vector<int> value(M,0);
    for(int i=0;i<M;i++) cin>>weight[i];
    for(int i=0;i<M;i++) cin>>value[i];
    // 生成最大列标到baseWeight的二维数组
    // row 物品 col 背包容量
    // dp[row][col] 任取下标在[0-row]的物品在背包容量为col下的最大值
    vector<vector<int>> dp(M,vector<int>(baseWeight+1,0));
    // 初始化 将第一行初始完毕 后序每行都依赖于上一行
    for(int i = weight[0];i<=baseWeight;i++){
        dp[0][i] =  value[0];
    }
    for(int i = 1;i<M;i++){
        for(int j = 0;j<=baseWeight;j++){
            if(j<weight[i]) dp[i][j] = dp[i-1][j];
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
            }
            // cout<<dp[i][j]<<" ";
        }
        // cout<<endl;
    }
    cout<<dp[M-1][baseWeight];
    return 0;
}