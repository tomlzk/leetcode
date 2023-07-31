/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        vector<int> mv(2);
        mv = intervals[0];
        int i = 0;
        if(intervals.size() == 1)
        {
            return intervals;
        }
        for(i = 1; i < intervals.size(); i++)
        {
            if(mv[1] >= intervals[i][0])
            {
                mv[1] = max(mv[1], intervals[i][1]);
            }
            else
            {
                v.push_back(mv);
                mv[0] = intervals[i][0];
                mv[1] = intervals[i][1];
            }
        }
        v.push_back(mv);
        return v;
    }
};
// @lc code=end
