/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) 
    {
        if(n == 1)
        {
            return 1;
        }
        vector<int> temp(n + 1);
        temp[0] = 1;
        temp[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            temp[i] = temp[i - 1] + temp[i - 2];
        }
        return *(temp.end() - 1);
    }
};
// @lc code=end

