/*
 * @lc app=leetcode.cn id=93 lang=cpp
 * @lcpr version=30204
 *
 * [93] 复原 IP 地址
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
    vector<string> result;
    // 判断字符串s在左闭右闭区间[start, end]所组成的数字是否合法
    bool isValid(const string& s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) { // 0开头的数字不合法
                return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] > '9' || s[i] < '0') { // 遇到非数字字符不合法
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) { // 如果大于255了不合法
                return false;
            }
        }
        return true;
    }
    void backtracking(string& s,int startIndex,int pointNum){
            if(pointNum==3){
                if(isValid(s,startIndex,s.size()-1)){
                    // 为什么加入s? 因为是在s中添加".",
                    result.push_back(s);
                }
            }
            for(int i = startIndex;i<s.size();i++){
                if(isValid(s,startIndex,i)){
                    pointNum++;
                    s.insert(s.begin()+i+1,'.');
                    backtracking(s,i+2,pointNum);
                    pointNum--;
                    s.erase(s.begin()+i+1);
                }
                else break;
            }
    }
    vector<string> restoreIpAddresses(string s) {
        // 剪枝
        // 小于4或>12的都是不合法的，所以s可以直接加入
        if(s.size()<4||s.size()>12) return result;
        backtracking(s,0,0);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "25525511135"\n
// @lcpr case=end

// @lcpr case=start
// "0000"\n
// @lcpr case=end

// @lcpr case=start
// "101023"\n
// @lcpr case=end

 */

