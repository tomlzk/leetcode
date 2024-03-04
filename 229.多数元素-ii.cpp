/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 多数元素 II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> cnt;

        for (auto & v : nums) {
            cnt[v]++;
        }
        for (auto & v : cnt) {
            if (v.second > n / 3) {
                ans.push_back(v.first);
            }
        }

        return ans;
    }
};
// @lc code=end

