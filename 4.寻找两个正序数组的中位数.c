/*
 * @lc app=leetcode.cn id=4 lang=c
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double array[2060] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < nums1Size && j < nums2Size)
    {
        if(nums1[i] < nums2[j])
        {
            array[k] = nums1[i];
            k++;
            i++;
        }
        else
        {
            array[k] = nums2[j];
            k++;
            j++;
        }
    }

    while(i < nums1Size)
    {
        array[k] = nums1[i];
        k++;
        i++;
    }

    while(j < nums2Size)
    {
        array[k] = nums2[j];
        k++;
        j++;
    }
    for(int n = 0; n < k; n++)
    {
        printf("%lf\n", array[n]);
    }
    printf("%d", k);
    k = k - 1;

    if(k % 2 == 0)
    {
        return array[k/2];
    }
    else
    {
        double number = (array[k/2] + array[k/2 + 1])/2;
        return number;
    }
}
// @lc code=end

