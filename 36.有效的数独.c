/*
 * @lc app=leetcode.cn id=36 lang=c
 *
 * [36] 有效的数独
 */

// @lc code=start

#include <stdbool.h>
bool judgeit(char **board, int left, int right, int up, int down);
bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
    int i = 0;
    int j = 0;
    int k = 0;
    printf("%d\n", board[0][0]);
    // 判断行条件符不符合
    while (i < 9)
    {
        int array[10] = {0, 0};
        for (j = 0; j < 9; j++)
        {
            k = board[i][j] - 48;
            if (k < 0)
            {
                continue;
            }
            if (array[k] == 1)

            {
                return false;
            }
            else
            {
                array[k] = 1;
            }
        }
        i++;
    }

    // 判断列符不符合条件
    i = 0;
    j = 0;

    while (j < 9)
    {
        int array[10] = {0};
        for (i = 0; i < 9; i++)
        {
            k = board[i][j] - 48;
            if (k < 0)
            {
                continue;
            }
            if (array[k] == 1)
            {
                return false;
            }
            else
            {
                array[k] = 1;
            }
        }
        j++;
    }

    // 判断3*3的宫格内符不符合条件
    i = 0;
    j = 0;
    bool result;
    for (; i <= 6; i = i + 3)
    {
        for (j = 0; j <= 6; j = j + 3)
        {
            if (!(judgeit(board, i, i + 3, j, j + 3)))
            {
                return false;
            }
        }
    }

    return true;
}

bool judgeit(char **board, int left, int right, int up, int down)
{
    int array[10] = {0};
    int k = 0;
    int beginofup = up;
    for (; left < right; left++)
    {
        for (up = beginofup; up < down; up++)
        {
            k = board[up][left] - 48;
            if (k < 0)
            {
                continue;
            }

            if (array[k] == 1)
            {
                return false;
            }
            else
            {
                array[k] = 1;
            }
        }
    }
    return true;
}
// @lc code=end
