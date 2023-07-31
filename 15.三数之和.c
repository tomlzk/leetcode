/*
 * @lc app=leetcode.cn id=15 lang=c
 *
 * [15] 三数之和
 */

// @lc code=start
int cmp(const void *pi, const void *pd)
{
    int a = *(int *)(pi);
    int b = *(int *)(pd);
    return a > b ? 1 : -1;
}
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int base = 3000;
    int **result = (int **)malloc(sizeof(int *) * base);
    (*returnSize) = 0;
    int i = 0;
    int j = 0;
    int k = numsSize - 1;
    int array[numsSize];
    qsort(nums, numsSize, sizeof(int), cmp);
    for(int m = 0; m < numsSize; m++)
    {
        printf("%d\n", nums[m]);
    }
    printf("\n");
    while (i < numsSize - 2)
    {
        j = i + 1;
        k = numsSize - 1;

        while (j < k)
        {
            int number = nums[i] + nums[j] + nums[k];
            if (number == 0)
            {
                result[*returnSize] = (int *)malloc(sizeof(int) * 3);
                result[*returnSize]=(int*)malloc(sizeof(int)*3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[j];
                result[*returnSize][2] = nums[k];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                if(*returnSize == base)
                {
                    base = base * 2;
                    result=(int**)realloc(result,sizeof(int*)*base);
                    *returnColumnSizes=(int*)realloc(*returnColumnSizes,sizeof(int)*base);
                }

                int nums1 = nums[j];
                int nums2 = nums[k];
                while (j < k && nums1 == nums[j])
                {
                    j++;
                }
                while (j < k && nums2 == nums[k])
                {
                    k--;
                }
            }
            else
            {
                if (number < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }

        while (i + 1 < numsSize && nums[i] == nums[i + 1])
        {
            i++;
        }
        i++;
    }

    return result;
}
// @lc code=end
