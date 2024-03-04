/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
class Solution
{

    void prepar(vector<vector<char>> &grid, int x, int y, int m, int n)
    {
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1')
        {
            return ;
        }

        grid[x][y] = 'A';

        prepar(grid, x + 1, y, m, n);
        prepar(grid, x - 1, y, m, n);
        prepar(grid, x, y - 1, m, n);
        prepar(grid, x, y + 1, m, n);

    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        vector<vector<char>> temp = grid;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(temp[i][j] == '1')
                {
                    prepar(temp, i, j, m, n);
                    count++;
                } 
            }
        }
        
        return count;
    }
};
// @lc code=end
