/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start

#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        if(nums.size() == 0)
        {
            return 0;
        }

        if(nums.size() == 1)
        {
            return 1;
        }
        sort(nums.begin(), nums.end());

        for(vector<int>::iterator it = nums.begin(); it < nums.end(); it++)
        {
            cout<<*it<<endl;
        }
        int maxSize = 0;
        int temp = 0;
        for(vector<int>::iterator it = nums.begin(); it < nums.end() - 1; it++)
        {
            if(*(it + 1) - *(it) == 1)
            {
                temp++;
            }
            else if(*(it + 1) - *(it) == 0)
            {
                
            }
            else
            {
                maxSize = maxSize > temp ? maxSize : temp;
                temp = 0;
            }
        }
        maxSize = maxSize > temp ? maxSize : temp;
        return maxSize + 1;
    }
};
// @lc code=end

