/*
 * @lc app=leetcode.cn id=16 lang=c
 *
 * [16] 最接近的三数之和
 */

// @lc code=start

int compare(const void *p1, const void *p2);
int threeSumClosest(int* nums, int numsSize, int target)
{
    int goodnumber = nums[0] + nums[1] + nums[2];
    int tempofit = 0;
    int number;

    int k;
    int i = 0;
    int j = numsSize - 1;
    qsort(nums, numsSize, sizeof(int), compare);

    for(k = 0; k < numsSize -2; k++)
    {
        if(k < numsSize - 2 && target < nums[k] + nums[k + 1] + nums[k + 2])
        {
            number = nums[k] + nums[k + 1] + nums[k + 2];
            goto error;
        }
        if(k < numsSize - 2 && target > nums[k] + nums[numsSize - 2] + nums[numsSize - 1])
        {
            number = nums[k] + nums[numsSize - 2] + nums[numsSize - 1];
            goto error;
        }
        for(i = k + 1, j = numsSize - 1; i < j; )
        {
            number = nums[k] + nums[i] + nums[j];
            goodnumber = abs(goodnumber - target) < abs(number - target) ? goodnumber : number;
            if(number - target < 0)
            {
                while(i < j && nums[i] == nums[i + 1])
                {
                    i++;
                }
                i++;
            }
            else if(number - target > 0)
            {
                while(j > i && nums[j] == nums[j - 1])
                {
                    j--;
                }
                j--;
            }
            else
            {
                return target;
            }
            printf("%d\n", number);


        }
        error:
        goodnumber = abs(goodnumber - target) < abs(number - target) ? goodnumber : number;
        while(k < numsSize - 2 && nums[k] == nums[k + 1])
        {
            k++;
        }
    }
    return goodnumber;
}

int compare(const void * p1, const void * p2)
{
    return *(int *)p1 - *(int *)p2;
}
// @lc code=end

