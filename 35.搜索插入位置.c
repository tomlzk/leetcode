/*
 * @lc app=leetcode.cn id=35 lang=c
 *
 * [35] 搜索插入位置
 */

// @lc code=start


int searchInsert(int* nums, int numsSize, int target)
{
    int i = 0;
    int j = numsSize;
    int mid = 0;
    if(target < nums[0])
    {
        return 0;
    }
    if(target > nums[numsSize - 1])
    {
        return numsSize;
    }

    while(j - i > 1)
    {
        mid = (i + j) / 2;
        if(nums[mid] > target)
        {
            j = mid;
        }
        else if(nums[mid] < target)
        {
            i = mid;
        }
        else
        {
            return mid;
        }
    }

    while(i < j)
    {
        if(nums[i] == target)
        {
            return i;
        }
        i++;
    }

    return i;
}
// @lc code=end

