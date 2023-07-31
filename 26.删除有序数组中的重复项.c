/*
 * @lc app=leetcode.cn id=26 lang=c
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start


int removeDuplicates(int* nums, int numsSize)
{
    int i = 0;
    int j;

    for(j = 1; j < numsSize; j++)
    {
        if(nums[j] != nums[j - 1])
        {
            nums[i] = nums[j - 1];
            i++;
        }
    }
    nums[i] = nums[j - 1];
    return i + 1;
}
// @lc code=end

