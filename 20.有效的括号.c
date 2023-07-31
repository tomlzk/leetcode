/*
 * @lc app=leetcode.cn id=20 lang=c
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<stdbool.h>

bool isValid(char * s)
{
    int length = strlen(s);
    int j = 0;
    int k = 0;
    while(j < length - 1)
    {
        if(s[j] == '(')
        {
            if(s[j + 1] == ')')
            {
                j = j + 2;
            }
            else
            {
                return false;
            }
        }
        if(s[j] == '[')
        {
            if(s[j + 1] == ']')
            {
                j = j + 2;
            }
            else
            {
                return false;
            }
        }
        if(s[j] == '{')
        {
            if(s[j + 1] == '}')
            {
                j = j + 2;
            }
            else
            {
                return false;
            }
        }
    }
    return true;
}
// @lc code=end

