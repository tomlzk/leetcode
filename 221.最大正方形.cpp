/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start

#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int length = matrix[0].size();
        int height = matrix.size();
        int max = 0;
        vector<vector<int>> res(height, vector<int>(length, 0));

        for(int i = 0; i < length; i++)
        {
            if(matrix[0][i] == '1')
            {
                max = 1;
                res[0][i] = 1;
            }
        }

        for(int i = 0; i < height; i++)
        {
            if(matrix[i][0] == '1')
            {
                max = 1;
                res[i][0] = 1;
            }
        }

        for(int i = 1; i < height; i++)
        {
            for(int j = 1; j < length; j++)
            {
                if(matrix[i][j] == '1')
                {
                    res[i][j] = min(res[i - 1][j], min(res[i - 1][j - 1], res[i][j - 1])) + 1;
                    max = max > res[i][j] ? max : res[i][j];
                }
                else
                {
                    res[i][j] = 0;
                }
            }
        }
        return max * max;
    }
};
// @lc code=end

