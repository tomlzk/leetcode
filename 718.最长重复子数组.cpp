/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */

// @lc code=start
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        string str1 = "";
        string str2 = "";
        map<string, int> judge;
        //memset(judge, 0, sizeof(judge));
        int maxLength = 0;
        vector<int> length1;
        vector<int> length2;
        for(vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++)
        {
            string temp = to_string(*it);
            str1 = str1 + temp;
            length1.push_back(temp.size());
        }
        for(vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++)
        {
            string temp = to_string(*it);
            str2 = str2 + temp;
            length2.push_back(temp.size());
        }

        
        for(int i = 0, m = 0; i < str1.size() && m < length1.size();)
        {
            int length = 0;

            for(int j = m; j < length1.size(); j++)
            {
                length = length + length1[j];
                string temp = str1.substr(i, length);
                if(judge[temp] == 0)
                {
                    judge[temp] = j - m + 1;
                }
            }
            i = i + length1[m];
            m++;
        }

        
        for(int i = 0, m = 0; i < str2.size() && m < length2.size();)
        {
            int length = 0;
            for(int j = m; j < length2.size(); j++)
            {
                length = length + length2[j];
                string temp = str2.substr(i, length);
                if(judge[temp] == j- m + 1 && maxLength < j - m + 1)
                {
                    maxLength = j - m + 1;
                }
            }
            i = i + length2[m];
            m++;
        }

        return maxLength;
    }
};
// @lc code=end

