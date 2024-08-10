#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    vector<int> sum(n+1,0);
    // sum[0] = nums[0];
    for(int i = 0;i<n;i++){
        cin>>nums[i];
        sum[i+1] = sum[i] + nums[i];
        
    }
    int a,b;
    while(scanf("%d %d",&a,&b)){
        int ans = sum[b+1] - sum[a];
        printf("%d",ans);
    }
    return 0;
}
