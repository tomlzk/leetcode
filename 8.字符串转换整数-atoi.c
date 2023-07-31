#include <math.h>
/*
 * @lc app=leetcode.cn id=8 lang=c
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
int myAtoi(char *s)
{
    int len = strlen(s);
    int i = 0;
    long digit = 0;
    long number = 0;
    int count = 0;
    while (s[i] == ' ')
    {
        i++;
    }
    if (s[i] == '-')
    {
        count = 1;
        i++;
    }
    else if(s[i] == '+')
    {
        i++;
    }
    while (i < len)
    {
        if (isdigit(s[i]) != 0)
        {
            if (number > 214748364)
            {
                if(count == 0)
                {
                    return pow(2, 31) - 1;
                }
                else
                {
                    return -pow(2, 31);
                }
            }
            if(number == 214748364&&count == 0&&(s[i] - 48) > 7)
            {
                return pow(2, 31) - 1;
            }
            if(number == 214748364&&count == 1&&(s[i] - 48) > 8)
            {
                return -pow(2, 31);
            }
            number = number * 10 + (s[i] - 48);
        }
        else
        {
            break;
        }
        i++;
    }

    if(count == 0)
    {
        return number;
    }
    else
    {
        return -number;
    }
}
// @lc code=end
