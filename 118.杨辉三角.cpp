/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> v;
        v.resize(numRows);
        for(int i = 0; i < numRows; i++)
        {
            v[i].resize(i + 1);
            v[i][0] = 1;
            for(int j = 1; j < i; j++)
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
            v[i][i] = 1;
        }
        return v;
    }
};
// @lc code=end
