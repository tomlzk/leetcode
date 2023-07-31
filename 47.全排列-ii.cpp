/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
#include<algorithm>
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        vector<int> mv;
        mv.resize(nums.size());
        backstrack(v, mv, nums, 0);
        return v;
    }
    void backstrack(vector<vector<int>> &v, vector<int> &mv, vector<int> nums, int index)
    {
        if(index == nums.size())
        {
            v.push_back(mv);
            return ;
        }
        sort(nums.begin() + index, nums.end());
        for(int i = index; i < nums.size(); i++)
        {
            if(nums[i] == nums[index] && i != index)
            {
                continue;
            }
            else
            {
                while(i < nums.size() - 1 && nums[i] == nums[i + 1])
                {
                    i++;
                }
            }

            swap(nums[i], nums[index]);
            mv[index] = nums[index];
            backstrack(v, mv, nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};
// @lc code=end
