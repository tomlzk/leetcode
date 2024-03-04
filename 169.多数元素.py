#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 多数元素
#

# @lc code=start
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        result = {}
        res = 0
        maxSize = 0

        for i in range(len(nums)) :
            if nums[i] not in result :
                result[nums[i]] = 1
            else :
                result[nums[i]] += 1
            
        for key, value in result.items() :
            if value > maxSize :
                maxSize = value
                res = key
        
        return res
# @lc code=end

