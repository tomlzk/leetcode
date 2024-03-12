/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        vector<int> result(s.size(), 0);
        for (int i = 1, j = 0; i < s.size(); i++)
        {
            while (j != 0 && s[i] != s[j])
            {
                j = result[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            result[i] = j;
        }

        if(result.back() != 0 && s.size() % (s.size() - result.back()) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
// @lc code=end
