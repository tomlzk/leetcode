/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
#include <iostream>
#include<algorithm>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> v;
        if(candidates.empty())
        {
            return v;
        }
        vector<int> mv;
        int index = 0;
        int sum = 0;
        backstrack(v, mv, candidates, target, 0, 0);
        return v;
    }
    void backstrack(vector<vector<int>> &v, vector<int> mv, vector<int> &candidates, int target, int index, int sum)
    {
        if(sum == target)
        {
            v.push_back(mv);
            return;
        }
        else if(sum > target)
        {
            return;
        }
        if(index >= candidates.size())
        {
            return;
        }
        backstrack(v, mv, candidates, target, index + 1, sum);

        int number = candidates[index];
        
        mv.push_back(number);
        backstrack(v, mv, candidates, target, index, sum + number);
        //mv.pop_back();
        
    }
};
// @lc code=end
