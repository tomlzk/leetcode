// @before-stub-for-debug-begin
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include<algorithm>
#include<iostream>
using namespace std;
#include<vector>
class Solution
{
public:
    int count = 1000;
    void backstrack(vector<vector<int>> &v, vector<int> &mv, vector<int> &candidates, int target, int index, int sum)
    {
        if(sum == target)
        {
            v.push_back(mv);
            return;
        }
        if(sum > target)
        {
            return ;
        }
        if(index >= candidates.size())
        {
            return;
        }
        for(int i = index; i < candidates.size(); i++)
        {
            if(count == candidates[i])
            {
                continue;
            }
            mv.push_back(candidates[i]);
            backstrack(v, mv, candidates, target, i + 1, candidates[i] + sum);
            count = candidates[i];
            //*(mv.end() - 1) = 10000;
        }
        return ;
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        cout<<*candidates.begin()<<endl;
        vector<vector<int>> v;
        vector<int> mv;
        backstrack(v, mv, candidates, target, 0, 0);
        return v;
    }
};
// @lc code=end
