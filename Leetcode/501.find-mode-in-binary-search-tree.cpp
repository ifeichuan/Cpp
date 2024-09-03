/*
 * @lc app=leetcode.cn id=501 lang=cpp
 * @lcpr version=30204
 *
 * [501] 二叉搜索树中的众数
 */


// @lcpr-template-start
using namespace std;
#include"tree.h"
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// 递归的判断pre指针是否与cur值相同 
class Solution {
private:
    int count = 0;
    int maxCount = 0;
    TreeNode* pre = NULL;
    vector<int> result;
    void searchBST(TreeNode* cur){
        if(!cur) return;
        searchBST(cur->left);
        if(!pre){
            count = 1;
        }
        else if(pre->val==cur->val){
            count++;
        }
        else{
            count=1;
        }
        pre = cur;
        if(count == maxCount){
             result.push_back(cur->val);
        }
        if(count > maxCount){
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }
        searchBST(cur->right);
        return ;
    }
public:
    vector<int> findMode(TreeNode* root) {
        result.clear();
        searchBST(root);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,null,2,2]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n
// @lcpr case=end

 */

