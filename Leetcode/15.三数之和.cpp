/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int i = 0, left, right;
        int t = 0;
        for (; i < nums.size() - 1; i++)
        {
            if (nums[i] > 0)
            {
                return ans;
            }
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            left = i + 1;
            right = nums.size() - 1;
            int sum = nums[i] + nums[left] + nums[right];
            ;
            while (left < right)
            {
                if (sum > 0)
                {
                    right--;
                }
                if (sum < 0)
                {
                    left++;
                }
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1])
                        right--;
                    while (right > left && nums[left] == nums[left + 1])
                        left++;

                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
                sum = nums[i] + nums[left] + nums[right];
            }
        }
        return ans;
    }
};
// @lc code=end
