/*
 * @lc app=leetcode.cn id=53 lang=java
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
    public int maxSubArray(int[] nums) 
    {
        int[] temp = new int[nums.length];
        temp[0] = nums[0];
        int maxSize = nums[0];
        for(int i = 1; i < nums.length; i++)
        {
            if(temp[i - 1] > 0)
            {
                temp[i] = temp[i - 1] + nums[i];
            }
            else
            {
                temp[i] = nums[i];
            }
            maxSize = maxSize > temp[i] ? maxSize : temp[i];
        }
        return maxSize;
    }
}
// @lc code=end

