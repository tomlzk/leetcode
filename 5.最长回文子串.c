/*
 * @lc app=leetcode.cn id=5 lang=c
 *
 * [5] 最长回文子串
 */

// @lc code=start

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
char *longestPalindrome(char *s)
{
    char array[1001] = {0};

    int len = strlen(s);
    int i = 0;
    int j = 0;
    int now;
    int max = 0;
    if (len == 0)
    {
        return 0;
    }
    if (len == 1)
    {
        return s;
    }

    for (; i < len; i++)
    {
        now = -1;
        while (true)
        {
            if (i - j >= 0 && i + j < len)
            {
                if (s[i - j] == s[i + j])
                {
                    j++;
                    now = now + 2;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            if (now > max)
            {
                max = now;
                int n = 0;
                int k = i - j + 1;
                for (; k < i + j; k++, n++)
                {
                    array[n] = s[k];
                }
                array[n] = '\0';
            }
        }
        j = 0;
    }

    for (i = 0; i < len - 1; i++)
    {
        now = 0;
        while (true)
        {
            if (i - j >= 0 && i + j < len)
            {
                if (s[i - j] == s[i + 1 + j])
                {
                    j++;
                    now = now + 2;
                }
                else
                {
                    break;
                }
            }
            else
            {
                break;
            }
            if (now > max)
            {
                max = now;
                int n = 0;
                int k = i - j + 1;
                for (; k <= i + j; k++, n++)
                {
                    array[n] = s[k];
                }
                array[n] = '\0';
            }
        }
        j = 0;
    }
    strcpy(s, array);
    
    return s;
}