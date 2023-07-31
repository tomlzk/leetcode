/*
 * @lc app=leetcode.cn id=34 lang=c
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize)
{
    int i = 0;
    int j = 0;
    (*returnSize) = 2;
    int *array = (int *)malloc(sizeof(int) * 2);
    array[0] = -1;
    array[1] = -1;
    for(; i < numsSize; i++)
    {
        if(nums[i] == target)
        {
            array[j] = i;
            j++;
            while(i < numsSize && nums[i] == target)
            {
                i++;
            }
            array[j] = i - 1;
        }
    }
    return array;
}
// @lc code=end

