#include <stdbool.h>
/*
 * @lc app=leetcode.cn id=10 lang=c
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

bool isMatch(char *s, char *p)
{
    int len = strlen(s);
    int len2 = strlen(p);
    int i = 0;
    int j = 0;
    int count = 0;
    int digit = 0;
    int k = 2;
    while (i < len)
    {
        if (s[i] == p[j])
        {
            i++;
            j++;
        }
        else if (p[j] == '.')
        {
            i++;
            j++;
        }
        else if (p[j] == '*')
        {
            if (p[j - 1] == '.')
            {
                if (j == len2 - 1)
                {
                    return true;
                }
                else
                {
                    j++;
                    while(p[j] == '.'&&k > 0)
                    {
                        j++;
                        k--;
                    }
                    while (p[j] != s[i]&&j < len2)
                    {
                        if(p[j + 1] == '*')
                        {
                            j = j + 2;
                            continue;
                        }
                        i++;
                        if (i >= len)
                        {
                            return false;
                        }
                    }
                    i++;
                    j++;
                }
            }
            else
            {
                j++;
                count = 0;
                while (s[i] == s[i - 1])
                {
                    i++;
                    count++;
                }
                while (j < len2 && count != 0)
                {
                    if (p[j] == s[i - 1])
                    {
                        j++;
                        count--;
                    }
                    else if (j + 1 < len2 && p[j + 1] == '*')
                    {
                        j = j + 2;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        else if (j + 1 < len2 && p[j + 1] == '*')
        {
            j = j + 2;
        }
        else
        {
            return false;
        }
    }
    while (j < len2)
    {
        if (p[j] == '*')
        {
            if (j == len2 - 1)
            {
                return true;
            }
            else if (p[j + 1] == s[i - 1]|| p[j + 1] == '.')
            {
                j = j + 2;
            }
            else
            {
                j++;
            }
        }
        else if (p[j] == '.')
        {
            if (j + 1 < len2 && p[j + 1] == '*')
            {
                j = j + 2;
            }
            else
            {
                return false;
            }

        }
        else if (j + 1 < len2 && p[j + 1] == '*')
        {
            j = j + 2;
        }
        else
        {
            return false;
        }
    }
    return true;
}
// @lc code=end
