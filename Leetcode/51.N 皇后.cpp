/*
 * @lc app=leetcode.cn id=51 lang=cpp
 * @lcpr version=30204
 *
 * [51] N 皇后
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
    vector<vector<string>> result;
    bool isValid(int row,int col,vector<string>& chessboard,int n){
        // 检查同列是否有相同的
        for(int i = 0;i<row;i++){
            if(chessboard[i][col]=='Q') return false;
        }
        // 检查左斜对角线 从上往下
        for(int i = row-1,j = col-1;i>=0&&j>=0;i--,j--){
            if(chessboard[i][j]=='Q') return false;
        }
        // 检查右斜对角线 从下往上
        for(int i  = row-1,j=col+1;i>=0&&j<n;i--,j++){
            if(chessboard[i][j]=='Q') return false;
        }
        return true;
    }

    void dfs(int n,int row,vector<string>& chessboard){
        if(row==n){
            result.push_back(chessboard);
            return;
        }
        // 每次从第1列开始遍历 可能会有重复所以需要减枝
        for(int col = 0;col<n;col++){
            if(isValid(row,col,chessboard,n)){
                // 放置皇后
                chessboard[row][col] = 'Q';
                dfs(n,row+1,chessboard);
                // 回溯
                chessboard[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // 先生成一个n*n的矩阵置为全 '.'
           vector<string> chessboard(n,string(n,'.'));
           dfs(n,0,chessboard);
           return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 4\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

