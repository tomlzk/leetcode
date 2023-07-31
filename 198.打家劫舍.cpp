// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem198.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int i = 0;
        int length = nums.size();
        if(length == 0)
        {
            return 0;
        }
        if(length == 1)
        {
            return nums[0];
        }
        vector<int> v(length, 0);
        v[0] = nums[0];
        v[1] = max(nums[0] , nums[1]);
        for(i = 2; i < length; i++)
        {
            v[i] = max(v[i - 1], v[i - 2] + nums[i]);
        }
        return *(v.end() - 1);
    }
};
// @lc code=end
