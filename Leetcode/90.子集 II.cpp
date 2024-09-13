/*
 * @lc app=leetcode.cn id=90 lang=cpp
 * @lcpr version=30204
 *
 * [90] 子集 II
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
    vector<vector<int>> result;
    vector<int> path;
    void traversal(vector<int>& nums,int startIndex){
        // 递归终止条件 达到数组末尾。
        result.push_back(path);
        for(int i = startIndex;i<nums.size();i++){
            if(i>startIndex&&nums[i]==nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            traversal(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        traversal(nums,0);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,4,4,1,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

