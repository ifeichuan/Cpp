/*
 * @lc app=leetcode.cn id=78 lang=cpp
 * @lcpr version=30204
 *
 * [78] 子集
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
        result.push_back(path);
        for(int i = startIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            
            traversal(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        traversal(nums,0);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

