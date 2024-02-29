--
-- @lc app=leetcode.cn id=607 lang=mysql
--
-- [607] 销售员
--

-- @lc code=start
# Write your MySQL query statement below
-- select com_id from Company where name = 'RED'
-- select sales_id from Orders where com_id = [] 
select name from SalesPerson where sales_id not in (select sales_id from Orders where com_id = (select com_id from Company where name = 'RED'));
-- @lc code=end

