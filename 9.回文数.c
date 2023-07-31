#include<stdbool.h>
/*
 * @lc app=leetcode.cn id=9 lang=c
 *
 * [9] 回文数
 */

// @lc code=start

bool isPalindrome(int x)
{
    if(x < 0)
    {
        return false;
    }
    long number = 0;
    long count = 0;
    count = x;
    while(x > 0)
    {
        number = number * 10 + x%10;
        x = x / 10;

    }
    if(number == count)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// @lc code=end

