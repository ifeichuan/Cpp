/*
 * @lc app=leetcode.cn id=131 lang=cpp
 * @lcpr version=30204
 *
 * [131] 分割回文串
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
    vector<string> path;
    bool isPalindrome(string s,int start,int end){
    for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
    }
    void backtracking(string&s,int startIndex){
        if(startIndex>=s.size()){
            result.push_back(path);
            return;
        }
        for(int i = startIndex;i<s.size();i++){
            // 判断startIndex-i是否是回文字符串
            // a aa aab
            if(isPalindrome(s,startIndex,i)){
            string str = s.substr(startIndex,i-startIndex+1);
            path.push_back(str);
            }
            else{
                continue;
            }
        // 递归用来纵向遍历,for循环用来横向遍历,切割线切割到字符串的结尾位置,说明找到了
        // a a b
        backtracking(s,i+1);
        path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "aab"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

 */

