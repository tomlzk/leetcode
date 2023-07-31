/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for(vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
        {
            cout<<*it<<endl;
        }
    }
};
// @lc code=end
