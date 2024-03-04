/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
class Solution
{
public:
    vector<vector<int>> result;

    void back(vector<int> res, int i, int n, int k)
    {
        if (res.size() == k)
        {
            result.push_back(res);
            // res.pop_back();
            //  back(res, i + 1, n, k);
            return;
        }
        if (i > n)
        {
            return;
        }

        for (int j = i; j <= n; j++)
        {
            res.push_back(j);
            back(res, j + 1, n, k);
            res.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<int> res;
        // for(int i = 1; i <= n; i++)
        // {
        //     res.push_back(i);
        //     back(res, i + 1, n, k);
        //     res.pop_back();

        // }
        back(res, 1, n, k);
        return result;
    }
};
// @lc code=end
