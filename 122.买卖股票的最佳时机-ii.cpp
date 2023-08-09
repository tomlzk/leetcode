/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int i = 0;
        vector<vector<int>> res;
        res.resize(prices.size());
        res[0].resize(2);
        res[0][0] = 0; res[0][1] = - prices[0];
        for(i = 1; i < prices.size(); i++)
        {
            res[i].resize(2);
            res[i][0] = max(res[i - 1][0], res[i - 1][1] + prices[i]);
            res[i][1] = max(res[i - 1][0] - prices[i], res[i - 1][1]);
        }
        i--;
        return max(res[i][0], res[i][1]);
    }
};
// @lc code=end

