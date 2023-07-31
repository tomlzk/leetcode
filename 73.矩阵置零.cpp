/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        vector<vector<int>> v;
        int i = 0;
        int j = 0;
        int k = 0;
        for(; i < matrix.size(); i++)
        {
            for(j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    v.resize(k + 1);
                    v[k].push_back(i);
                    v[k].push_back(j);
                    k++;
                }
            }
        }
        for(auto it = v.begin(); it != v.end(); it++)
        {
            int i = (*it)[0];
            int j = (*it)[1];
            for(int m = 0; m < matrix[0].size(); m++)
            {
                matrix[i][m] = 0;
            }
            for(int n = 0; n < matrix.size(); n++)
            {
                matrix[n][j] = 0;
            }
        }
    }
};
// @lc code=end
