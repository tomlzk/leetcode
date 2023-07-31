/*
 * @lc app=leetcode.cn id=7 lang=c
 *
 * [7] 整数反转
 */

// @lc code=start


int reverse(long x)
{
    int i = 0;
    int j = 0;
    long number = 0;
    long num = 0;
    if(x < 0)
    {
        i = -1;
        x = -x;
    }

    while(x > 0)
    {
        num = number;
        number = number*10 + x%10;
        x = x / 10;
        j++;
    }
    if(j > 10)
    {
        return 0;
    }
    if(j == 10 && num > 214748364)
    {
        return 0;
    }
    if(number > -2e+31 && number < 2e+31 - 1)
    {
        if(i == 0)
        {
            return number;
        }
        else
        {
            return -number;
        }
    }
    else
    {
        return 0;
    }
}
// @lc code=end

