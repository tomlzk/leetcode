/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> v;
        vector<int> mv;
        mv.resize(nums.size());
        backstrack(v, mv, nums, 0);
        return v;
    }
    void backstrack(vector<vector<int>> &v, vector<int> &mv, vector<int> &nums, int index)
    {
        if(index == nums.size())
        {
            v.push_back(mv);
            return ;
        }
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[i], nums[index]);
            mv[index] = nums[index];
            backstrack(v, mv, nums, index + 1);
            swap(nums[i], nums[index]);
        }
    }
};
// @lc code=end
