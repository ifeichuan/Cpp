/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
   int *curee = (int*)(malloc(sizeof(int)*2));
   for(int i =0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(target-nums[i]==nums[j]){
                curee[0] = i;
                curee[1] = j;
                *returnSize = 2;
                return curee;
            }
        }
   }
}
// @lc code=end

