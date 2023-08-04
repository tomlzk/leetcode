/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */

// @lc code=start

#include<iostream>
using namespace std;
#include<vector>
#include<string>

class Solution {
public:
    int numDecodings(string s) 
    {
        vector<int> temp(s.size());
        temp[0] = 1;

        if(s[0] == '0')
        {
            return 0;
        }
        if(s.size() == 1)
        {
            return 1;
        }

        if((s[0] - 48) * 10 + (s[1] - 48) >= 10 && (s[0] - 48) * 10 + (s[1] - 48) <= 26)
        {
            if(s[1] == '0')
            {
                temp[1] = 1;
            }
            else
            {
                temp[1] = 2;
            }
        }
        else if(s[1] != '0')
        {
            temp[1] = 1;
        }
        else
        {
            return 0;
        }

        if(s.size() == 2)
        {
            return temp[1];
        }

        for(int i = 2; i < s.size(); i++)
        {
            if((s[i - 1] - 48) * 10 + s[i] - 48 >= 10 && (s[i - 1] - 48) * 10 + s[i] - 48 <= 26)
            {
                if(s[i] == '0')
                {
                    temp[i] = temp[i - 2];
                }
                else
                {
                    temp[i] = temp[i - 1] + temp[i - 2];
                }
            }
            else if(s[i] != '0')
            {
                temp[i] = temp[i - 1];
            }
            else
            {
                return 0;
            }
        }
        return temp[s.size() - 1];
    }
};
// @lc code=end

