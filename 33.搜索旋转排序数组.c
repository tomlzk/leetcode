/*
 * @lc app=leetcode.cn id=33 lang=c
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
int search(int *nums, int numsSize, int target)
{
    int sum = -1;
    if (nums[0] > target && nums[numsSize - 1] < target)
    {
        return sum;
    }
    if(target == nums[0])
    {
        return 0;
    }

    int m = 0;
    int yes = 0;
    for(; m < numsSize - 1; m++)
    {
        if(nums[m] > nums[m + 1])
        {
            yes = 1;
            break;
        }
    }
    int i = 0;
    int j = numsSize;
    if(yes == 1 && target > nums[0])
    {
        j = m + 1;
    }
    else if(yes == 1)
    {
        i = m + 1;
    }
    int mid = (i + j) / 2;
    while (j - i > 1)
    {
        mid = (i + j) / 2;
        if (nums[mid] > target)
        {
            j = mid;
        }
        else if (nums[mid] < target)
        {
            i = mid;
        }
        else
        {
            return mid;
        }
    }
    for (; i < j; i++)
    {
        if (nums[i] == target)
        {
            sum = i;
            break;
        }
    }
    printf("%d\n", sum);
    return sum;
}
// @lc code=end
