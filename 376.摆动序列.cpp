/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1)
        {
            return n;
        }
        if(n == 2)
        {
            if(nums[0] != nums[1])
            {
                return 2;
            }
            else
            {
                return 1;
            }
        }

        vector<int> up = vector<int>(n);
        vector<int> down = vector<int>(n);

        up[0] = 1;
        down[0] = 1;

        for(int i = 1; i < n; i++)
        {
            if(nums[i] > nums[i - 1])
            {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            }
            else if(nums[i] < nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            }
            else if(nums[i] == nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1] , down[n - 1]);
    }
};
// @lc code=end

