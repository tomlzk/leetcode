/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start

#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> res;
        int maxSize = 0;
        int flag = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            string temp = to_string(nums[i]);
            int size = temp.size();
            if (size > maxSize)
            {
                maxSize = size;
            }
            res.push_back(temp);
        }

        while (maxSize > 0)
        {
            for (int i = 0; i < res.size(); i++)
            {
                // for (int j = res.size() - 1; j > i; j--)
                // {
                //     if (res[j - 1].size() > flag)
                //     {
                //         if (res[j][flag] > res[j - 1][flag])
                //         {
                //             char temp = res[j][flag];
                //             res[j][flag] = res[j - 1][flag];
                //             res[j - 1][flag] = temp;
                //         }
                //     }
                //     else
                //     {

                //     }

                // }

                int j = res.size() - 1;
                int now = 0;
                while (j > i)
                {
                    if (res[now].size() > flag)
                    {
                        if (res[j][flag] > res[now][flag])
                        {
                            //             char temp = res[j][flag];
                            //             res[j][flag] = res[j - 1][flag];
                            //             res[j - 1][flag] = temp;
                        }
                    }
                }
            }
            flag++;
            maxSize--;
        }
    }
};
// @lc code=end
