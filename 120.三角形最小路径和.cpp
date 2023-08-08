/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start

#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int i = 0;
        int j = 0;
        for (i = triangle.size() - 2; i >= 0; i--)
        {
            for (j = 0; j < triangle[i].size(); j++)
            {
                int temp = triangle[i + 1][j] < triangle[i + 1][j + 1] ? triangle[i + 1][j] : triangle[i + 1][j + 1];
                triangle[i][j] = triangle[i][j] + temp;


            }
        }
        return triangle[0][0];
    }
};
// @lc code=end
