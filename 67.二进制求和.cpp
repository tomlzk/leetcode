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
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0;
        int maxI = a.size();
        int j = 0;
        int maxJ = b.size();

        while(i < maxI && j < maxJ)
        {
            if(a[i] == 1 && b[j] == 1)
            {
                
            }
        }

    }
};
// @lc code=end
