/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
//方法一，使用复制数组的方法(最简单),方法二使用python来写
#include<iostream>
using namespace std;
#include<vector>
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> matrixnew(n, vector<int>(n));
        //matrix[i][j]  --->   matrixnew[j][n - i - 1]
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrixnew[j][n - i - 1] = matrix[i][j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[i][j] = matrixnew[i][j];
            }
        }
    }
};
// @lc code=end

