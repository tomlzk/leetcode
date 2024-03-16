/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortback(vector<int> nums, int left, int right)
    {
        if(right - left <= 2)
        {
            vector<int> result;
            result.push_back(left);
            return result;;
        }
        int mid = left + (right - left) / 2;
        vector<int> temp1 = sortback(nums, left, mid);
        vector<int> temp2 = sortback(nums, mid, right);
        vector<int> result;

        int i = 0;
        int j = 0;
        int length1 = temp1.size();
        int length2 = temp2.size();
        
        while(i < length1 && j < length2)
        {
            if(temp1[i] < temp2[j])
            {
                result.push_back(temp1[i]);
                i++;
            }
            else
            {
                result.push_back(temp2[j]);
                j++;
            }
        }

        while(i < length1)
        {
            result.push_back(temp1[i]);
            i++;
        }

        while(j < length2)
        {
            result.push_back(temp2[j]);
            j++;
        }

        return result;
    }
    //归并排序
    vector<int> sortArray(vector<int>& nums)
    {
        return sortback(nums, 0, nums.size());
    }
};
// @lc code=end

