#include<iostream>
#include<vector>
using namespace std;

int main(){
    int M,baseWeight;
    cin>>M>>baseWeight;
    vector<int> weight(M,0);
    vector<int> value(M,0);
    for(int  i = 0;i<M;i++){
        cin>>weight[i];
    }
    for(int  i = 0;i<M;i++){
        cin>>value[i];
    }
    vector<int> dp(baseWeight+1,0);
    // 遍历每个物品的下标
    for(int i = 0;i<M;i++){
        // 背包容量要大于等于当前物品的重量
        for(int j = baseWeight;j>=weight[i];j--){
            // 从后往前遍历,确保物品i只被放入1次
            // weight[0] = 1 value[0] = 15 baseWeight = 3
            // i = 0 j = 1
            // dp[j] = max(dp[1],dp[1-1]+15) = 15
            // i = 0 j = 2
            // dp[j] = max(dp[2],dp[2-1]+15)  =30
            dp[j] = max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    cout<<dp[baseWeight];
    return 0;
}