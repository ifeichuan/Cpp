/*
 * @lc app=leetcode.cn id=491 lang=cpp
 * @lcpr version=30204
 *
 * [491] 非递减子序列
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
private:
    vector<vector<int>> result;
    vector<int> path;
    void traversal(vector<int>& nums,int startIndex){
        if(path.size()>1){
            result.push_back(path);
        }
        int used[201] = {0};
        for(int i = startIndex;i<nums.size();i++){
            if(!path.empty()&&nums[i]<path.back()||used[nums[i]+100]==1) continue;
            used[nums[i]+100]=1;
            path.push_back(nums[i]);
            traversal(nums,i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        // 子序列,不能排序
        // 递增需要每个元素nums[i]大于path.back(),也就是单调栈.
        // 去重可以用uesd表,但只在本层使用,所以每次需要重新定义
        traversal(nums,0);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,6,7,7]\n
// @lcpr case=end

// @lcpr case=start
// [4,4,3,2,1]\n
// @lcpr case=end

 */

