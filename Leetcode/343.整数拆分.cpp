/*
 * @lc app=leetcode.cn id=343 lang=cpp
 * @lcpr version=30204
 *
 * [343] 整数拆分
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        dp[0] = dp[1] = 0;
        // dp[i] = i的最大拆分正整数乘积
        for(int i = 2;i<=n;i++){
            int curMax = 0;
            for(int j = 1;j<i;j++){
                curMax = max(curMax,max(j*(i-j),j*dp[i-j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};
// @lc code=end



/*
// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

