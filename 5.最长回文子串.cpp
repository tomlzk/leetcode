/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <iostream>
using namespace std;
#include <string.h>
#include <stdbool.h>
#include <vector>
//思路：
class Solution {
public:
    string longestPalindrome(string s) 
    {
        int length = s.size();
        if(length < 2)
        {
            return s;
        }

        vector<vector<bool>> array(length, vector<bool>(length));

        int begin = 0;
        int maxlen = 1;

        for(int i = 0; i < length; i++)
        {
            array[i][i] = true;
        }

        for(int L = 2; L <= length; L++)
        {
            for(int i = 0; i < length; i++)
            {
                int j = i + L - 1;

                if(j >= length)
                {
                    break;
                }

                if(s[i] != s[j])
                {
                    array[i][j] = false;
                }
                else
                {
                    if(L == 2)
                    {
                        array[i][j] = true;
                    }
                    else
                    {
                        array[i][j] = array[i + 1][j - 1];
                    }
                }

                if(array[i][j] && j - i + 1 > maxlen)
                {
                    begin = i;
                    maxlen = L;

                }
            }
        }

        return s.substr(begin, maxlen);
    }
};
// @lc code=end

