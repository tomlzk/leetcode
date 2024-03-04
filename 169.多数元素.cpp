/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
#include <map>
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        map<int, int> result;
        int res = 0;
        int maxSize = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            if(result.find(nums[i]) == result.end())
            {
                result.insert(pair<int, int>(nums[i], 1));
            }
            else
            {
                result[nums[i]]++;
            }
        }


        for(map<int, int>::iterator it = result.begin(); it != result.end(); it++)
        {
            if(it->second > maxSize)
            {
                maxSize = it->second;
                res = it->first;
            }
        }

        if(maxSize > nums.size() / 2)
        {
            return res;
        }
        else
        {
            return 0;
        }
    }
};
// @lc code=end
