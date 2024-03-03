/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (target == 0)
        {
            return 0;
        }
        int i = 0;
        int j = 0;
        int length = nums.size();
        int count = length;
        int now = 0;
        int temp = 0;

        while (j < length)
        {
            if (now < target)
            {
                now = now + nums[j];
                j++;
                temp++;
            }
            else
            {
                if (count > temp)
                {
                    count = temp;
                }
                now = now - nums[i];
                i++;
                temp--;
                if (now == 0)
                {
                    return 1;
                }
                // if (count > temp)
                // {
                //     count = temp;
                // }
            }
        }

        while (now >= target)
        {
            if (count > temp)
            {
                count = temp;
            }
            now = now - nums[i];
            i++;
            temp--;
        }

        if(temp == length)
        {
            if(now == target)
            {
                return length;
            }
            else
            {
                return 0;
            }
        }

        return count;
    }
};
// @lc code=end
