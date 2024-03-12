--
-- @lc app=leetcode.cn id=619 lang=mysql
--
-- [619] 只出现一次的最大数字
--

-- @lc code=start
# Write your MySQL query statement below
select sum from MyNumbers group by num order by num desc having count(*) = 1
-- @lc code=end

