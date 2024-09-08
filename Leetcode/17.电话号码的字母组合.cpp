/*
 * @lc app=leetcode.cn id=17 lang=cpp
 * @lcpr version=30204
 *
 * [17] 电话号码的字母组合
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
        map<char,string> M{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
        };
vector<string> result;
string words;
    void traversal(string digits,int index){
        if(digits.size()==index){
            result.push_back(words);
            return;
        }
    char T = digits[index];
    string str = M[T];
    for(int i = 0;i<str.size();i++){
        words.push_back(str[i]);
        traversal(digits,index+1);
        words.pop_back();
    }
    }
    vector<string> letterCombinations(string digits) {       
        if(digits.size()==0) return {};
        traversal(digits,0);
        return result;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "23"\n
// @lcpr case=end

// @lcpr case=start
// ""\n
// @lcpr case=end

// @lcpr case=start
// "2"\n
// @lcpr case=end

 */

