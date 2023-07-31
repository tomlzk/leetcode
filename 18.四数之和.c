/*
 * @lc app=leetcode.cn id=18 lang=c
 *
 * [18] 四数之和
 */

// @lc code=start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
int compare(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}
int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), compare);
    int base = 3000;
    int **result = (int **)malloc(sizeof(int *) * base);
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * base);
    (*returnSize) = 0;

    int i = 0;
    int j = 0;
    int m = 0;
    int n = 0;
    int number = 0;
    if(numsSize < 4)
    {
        return result;
    }

    for (i = 0; i < numsSize - 3; i++)
    {
        for (j = i + 1; j < numsSize - 2; j++)
        {
            if (target < (long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2])
            {
                continue;
            }
            if (target > (long)nums[i] + nums[j] + nums[numsSize - 2] + nums[numsSize - 1])
            {
                continue;
            }
            m = j + 1;
            n = numsSize - 1;
            while (m < n)
            {
                long number = (long)nums[i] + nums[j] + nums[m] + nums[n];
                if (number == target)
                {
                    printf("1\n");
                    result[*returnSize] = (int *)malloc(sizeof(int) * 4);
                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[m];
                    result[*returnSize][3] = nums[n];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    if ((*returnSize) == base)
                    {
                        base = base * 2;
                        result = (int **)realloc(result, sizeof(int *) * base);
                    }

                    while (m < n && nums[m] == nums[m + 1])
                    {
                        m++;
                    }
                    m++;

                    while (m < n && nums[n] == nums[n - 1])
                    {
                        n--;
                    }
                    n--;
                }
                if (number > target)
                {
                    while (n > m && nums[n] == nums[n - 1])
                    {
                        n--;
                    }
                    n--;
                }
                if (number < target)
                {
                    while (n > m && nums[m] == nums[m + 1])
                    {
                        m++;
                    }
                    m++;
                }
            }
            while (j < numsSize - 1 && nums[j] == nums[j + 1])
            {
                j++;
            }
        }
        while (i < numsSize - 1 && nums[i] == nums[i + 1])
        {
            i++;
        }
    }
    return result;
}

// @lc code=end
