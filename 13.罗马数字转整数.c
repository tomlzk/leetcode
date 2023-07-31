/*
 * @lc app=leetcode.cn id=13 lang=c
 *
 * [13] 罗马数字转整数
 */

// @lc code=start


int romanToInt(char * s)
{
    int number = 0;
    int i = 0;
    int k = strlen(s);
    
    while(i < k)
    {
        if(s[i] == 'M')
        {
            number = number + 1000;
            i++;
        }
        else if(s[i] == 'C')
        {
            if(s[i + 1] == 'M' && i + 1 < k)
            {
                number = number + 900;
                i = i + 2;
            }
            else if(s[i + 1] == 'D' && i + 1 < k)
            {
                number = number + 400;
                i = i + 2;
            }
            else
            {
                number = number + 100;
                i++;
            }
        }
        else if(s[i] == 'D')
        {
            number = number + 500;
            i++;
        }
        else if(s[i] == 'X')
        {
            if(s[i + 1] == 'C' && i + 1 < k)
            {
                number = number + 90;
                i = i + 2;
            }
            else if(s[i + 1] == 'L' && i + 1 < k)
            {
                number = number + 40;
                i = i + 2;
            }
            else
            {
                number = number + 10;
                i++;
            }
        }
        else if(s[i] == 'L')
        {
            number = number + 50;
            i++;
        }
        else if(s[i] == 'I')
        {
            if(s[i + 1] == 'X'&& i + 1 < k)
            {
                number = number + 9;
                i = i + 2;
            }
            else if(s[i + 1] == 'V' && i + 1 < k)
            {
                number = number + 4;
                i = i + 2;
            }
            else
            {
                number = number + 1;
                i++;
            }
        }
        else if(s[i] == 'V')
        {
            number = number + 5;
            i++;
        }
    }
    return number;
}
// @lc code=end

