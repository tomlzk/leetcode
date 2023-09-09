/*
 * @lc app=leetcode.cn id=375 lang=java
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
class Solution {
    public int getMoneyAmount(int n) {
        int [][]res = new int[n + 1][n + 1];
        for(int i = n - 1; i >= 1; i--)
        {
            for(int j = i + 1; j < n + 1; j++)
            {
                res[i][j] = j + res[i][j - 1];
                for(int k = i; k < j; k++)
                {
                    res[i][j] = Math.min(res[i][j] , Math.max(res[i][k], res[k][j]));
                }
            }
        }

        return res[1][n];
    }
}
// @lc code=end

