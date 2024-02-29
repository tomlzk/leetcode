/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start

#include <iostream>
using namespace std;
#include <string>

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0;
        int maxI = a.size();
        int j = 0;
        int maxJ = b.size();
        int flag = 0;

        while (i < maxI && j < maxJ)
        {
            if (a[i] == '1' && b[j] == '1')
            {
                if (flag == 0)
                {
                    result = result + "0";
                }
                else
                {
                    result = result + "1";
                }
                flag = 1;
            }
            else if (a[i] == '0' && b[j] == '1')
            {
                if (flag == 0)
                {
                    result = result + "1";
                    flag = 0;
                }
                else
                {
                    result = result + "0";
                    flag = 1;
                }
            }
            else if (a[i] == '1' && b[i] == '0')
            {
                if (flag == 0)
                {
                    result = result + "1";
                    flag = 0;
                }
                else
                {
                    result = result + "0";
                    flag = 1;
                }
            }
            else if (a[i] == '0' && b[i] == '0')
            {
                if (flag == 0)
                {
                    result = result + "0";
                    flag = 0;
                }
                else
                {
                    result = result + "1";
                    flag = 0;
                }
            }
            i++;
            j++;
        }

        while (i < maxI)
        {
            if (flag == 0)
            {
                result = result + string(1, a[i]);
                i++;
            }
            else if(flag == 1)
            {
                if(a[i] == '1')
                {
                    result = result + "0";
                }
                else if(a[i] == '0')
                {
                    result = result + "1";
                    flag = 0;
                }
                i++;
            }
        }

        while (j < maxJ)
        {
            if (flag == 0)
            {
                result = result + string(1, b[j]);
                j++;
            }
            else if(flag == 1)
            {
                if(b[j] == '1')
                {
                    result = result + "0";
                }
                else if(b[j] == '0')
                {
                    result = result + "1";
                    flag = 0;
                }
                j++;
            }
        }

        if(flag == 1)
        {
            result = result + "1";
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
