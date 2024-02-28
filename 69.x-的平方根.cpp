// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem69.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution
{
public:
    unsigned long mySqrt(unsigned long x)
    {
        if(x == 0)
        {
            return 0;
        }

        unsigned long i = 0;

        for(; (i + 1) * (i + 1) <= x; i++)
        {
            
        }

        return i;
    }
};
// @lc code=end
