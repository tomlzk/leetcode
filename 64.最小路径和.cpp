/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        vector<vector<int>> v;
        int m = grid.size();
        int n = grid[0].size();
        v.resize(m);
        for(int i = 0; i < m; i++)
        {
            v[i].resize(n);
        }
        v[0][0] = grid[0][0];
        for(int i = 1; i < n; i++)
        {
            v[0][i] = grid[0][i] + v[0][i - 1];
        }
        for(int i = 1; i < m; i++)
        {
            v[i][0] = grid[i][0] + v[i - 1][0];
        }
        
        int i = 1;
        int j = 1;

        for(; i < m; i++)
        {
            for(j = 1; j < n; j++)
            {
                v[i][j] = min(v[i - 1][j], v[i][j - 1]) + grid[i][j];
            }
        }
        return v[m - 1][n - 1];
    }
};
// @lc code=end
