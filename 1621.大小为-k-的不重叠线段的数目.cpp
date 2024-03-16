/*
 * @lc app=leetcode.cn id=1621 lang=cpp
 *
 * [1621] 大小为 K 的不重叠线段的数目
 */

// @lc code=start
class Solution {
public:

    int sum = 0;
    void back(int left, int right, int count, int k)
    {
        count++;
        for(int i = left; i < right; i++)
        {
            for(int j = i + 1; j < right; j++)
            {
                if(count == k)
                {
                    sum++;
                    sum = sum + (right - j - 1) + ((right - i - 1) * (right - i - 2)) / 2;
                    return;
                }
                else
                {
                    back(j, right, count, k);
                }
            }
        }
    }

    int numberOfSets(int n, int k)
    {
        back(0, n, 0, k);
        return sum;
    }
};
// @lc code=end

