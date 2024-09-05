/*
 * @lc app=leetcode.cn id=235 lang=cpp
 * @lcpr version=30204
 *
 * [235] 二叉搜索树的最近公共祖先
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 只需要找到第一个值在[p,q]之间的结点即可.
        // 当根节点都大于p和q时,代表需要的结点在左边
        if(root->val>p->val&&root->val>q->val){
            TreeNode* left = lowestCommonAncestor(root->left,p,q);
            if(left) return left;
        }
        else if(root->val<p->val&&root->val<q->val){
            TreeNode* right = lowestCommonAncestor(root->right,p,q);
            if(right) return right;
        }
        return root;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n8\n
// @lcpr case=end

// @lcpr case=start
// [6,2,8,0,4,7,9,null,null,3,5]\n2\n4\n
// @lcpr case=end

 */

