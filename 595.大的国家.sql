--
-- @lc app=leetcode.cn id=595 lang=mysql
--
-- [595] 大的国家
--

-- @lc code=start
# Write your MySQL query statement below
select name,population,area from World where population >= 25000000 or area >= 3000000;
-- @lc code=end

