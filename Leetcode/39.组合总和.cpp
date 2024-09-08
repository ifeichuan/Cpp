/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * @lcpr version=30204
 *
 * [39] 组合总和
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
#include"tree.h"
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void traversal(vector<int>& candidates,int target,int sum,int index){
    if(target==sum){
            result.push_back(path);
            return;
        }
        for(int i = index;i<candidates.size()&&sum+candidates[i]<=target;i++){
            path.push_back(candidates[i]);
            // if(sum+candidates[i]>target) break;
            sum+=candidates[i];
            traversal(candidates,target,sum,i);
            sum-=candidates[i];
            path.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        traversal(candidates,target,0,0);
        return result;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,6,7]\n7\n
// @lcpr case=end

// @lcpr case=start
// [2,3,5]\n8\n
// @lcpr case=end

// @lcpr case=start
// [2]\n1\n
// @lcpr case=end

 */

