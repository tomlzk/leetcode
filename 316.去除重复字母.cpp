/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include <iostream>
#include <string>
#include<algorithm>
using namespace std;
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        string::iterator temp = s.begin();
        string::iterator now1;
        string::iterator now2;
        while(temp != s.end())
        {
            char c = *temp;
            int ccount = count(s.begin(), s.end(), *temp);
            for(string::iterator it = temp; it != s.end(),ccount > 1; it++)
            {
                if(c == *it)
                {
                    now1 = it;
                    if(now1 == now2)
                    {
                        s.erase(now2);
                        it--;
                        now1--;
                    }
                    now2 = now1;
                }
                else if(c < *it)
                {
                    while(it != s.end())
                    {
                        if(*it == c)
                        {
                            s.erase(it);
                            it--;
                        }
                        it++;
                    }
                }
                else if(c > *it)
                {
                    s.erase(now1);
                    it--;
                    ccount--;
                }
            }
        }
    }
};
// @lc code=end
