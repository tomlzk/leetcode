/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int i = 0;
        int j = 0;
        int m = 0;
        int n = 0;
        int k = 0;
        for(; k < s3.size(); k++)
        {
            if(s1[i] == s3[k])
            {
                i++;
            }
        }
    }
};
// @lc code=end
