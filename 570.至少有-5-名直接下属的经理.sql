--
-- @lc app=leetcode.cn id=570 lang=mysql
--
-- [570] 至少有5名直接下属的经理
--

-- @lc code=start
# Write your MySQL query statement below
select Employee.Name as Name
from (
  select ManagerId as Id
  from Employee
  group by ManagerId
  having count(Id) >= 5
) as Manager join Employee
on Manager.Id = Employee.Id
-- @lc code=end

