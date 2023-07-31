/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int m = nums.size();
        int temp = m - 1;
        while (temp > 0)
        {
            int now = temp;
            for (int i = temp; i >= 0; i--)
            {
                if (nums[i] >= temp - i)
                {
                    temp = min(temp, i);
                }
            }
            if(now == temp)
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
