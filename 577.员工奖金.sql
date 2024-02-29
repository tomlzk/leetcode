--
-- @lc app=leetcode.cn id=577 lang=mysql
--
-- [577] 员工奖金
--

-- @lc code=start
# Write your MySQL query statement below
select name, bonus
from Employee left join Bonus
on Employee.EmpId = Bonus.EmpId
where bonus is null or bonus < 1000
-- @lc code=end

