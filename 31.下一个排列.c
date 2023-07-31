/*
 * @lc app=leetcode.cn id=31 lang=c
 *
 * [31] 下一个排列
 */

// @lc code=start
void cmp(const void *p1, const void *p2)
{
    return *(int *)p1 - *(int *)p2;
}

void nextPermutation(int* nums, int numsSize)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int number = 0;
    for(i = numsSize - 1; i > 0; i--)
    {
        if(nums[i] > nums[i - 1])
        {
            j = i - 1;
            k = numsSize - 1;
            while(nums[k] <= nums[j])
            {
                k--;
            }
            int temp = nums[j];
            nums[j] = nums[k];
            nums[k] = temp;
            qsort((nums + i), (numsSize - i), sizeof(int), cmp);
            number = 1;
            break;
        }
    }

    if(number == 0)
    {
        for(int i = 0; i < numsSize / 2; i++)
        {
            int temp = nums[i];
            nums[i] = nums[numsSize - i - 1];
            nums[numsSize - i - 1] = temp;
        }
    }
}
// @lc code=end

