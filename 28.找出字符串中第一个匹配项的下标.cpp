/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        vector<int> v(needle.size());
        //v.resize(needle.size() + 1);
        for(int i = 1, j = 0; i < needle.size(); i++)
        {
            while(j > 0 && needle[i] != needle[j])
            {
                j = v[j - 1];
            }
            if(needle[i] == needle[j])
            {
                j++;
            }
            v[i] = j;
        }

        for(int i = 0,  j = 0; i < haystack.size()&&j < needle.size(); i++)
        {
            while(j > 0 && needle[j] != haystack[i])
            {
                j = v[j - 1];
            }
            if(haystack[i] == needle[j])
            {
                j++;
            }

            if(j == needle.size())
            {
                return i - j + 1;
            }
        }
        return -1;
    }
};
// @lc code=end
