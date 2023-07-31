/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>
class Solution
{
public:
    int digui(vector<int> v[],int m, int n)
    {
        if(m == 0)
        {
            v[0][n] = 1;
            return v[0][n];
        }
        if(n == 0)
        {
            v[m][0] = 1;
            return v[m][0];
        }

        v[m][n] = digui(v, m - 1, n) + digui(v, m, n - 1);
        return v[m][n];
    }
    int uniquePaths(int m, int n)
    {
        vector<int> v[m];
        for(int i = 0; i < m; i++)
        {
            v[i].resize(n);
        }
        return digui(v, m - 1, n - 1);
    }
};
// @lc code=end
