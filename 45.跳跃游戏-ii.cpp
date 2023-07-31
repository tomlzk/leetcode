/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int count = 0;
        vector<int>::iterator temp = nums.end() - 1;
        
        while(temp != nums.begin())
        {
            vector<int>::iterator now = temp;
            for(vector<int>::iterator it = temp - 1; it >= nums.begin(); it--)
            {
                if(*it >= (temp - it))
                {
                    now = it;
                }
            }
            temp = now;
            count++;
        }
        return count;
    }
};
// @lc code=end
