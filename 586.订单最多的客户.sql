--
-- @lc app=leetcode.cn id=586 lang=mysql
--
-- [586] 订单最多的客户
--

-- @lc code=start
-- # Write your MySQL query statement below

   --此代码是题解
-- SELECT
--     customer_number
-- FROM
--     orders
-- GROUP BY customer_number
-- ORDER BY COUNT(*) DESC
-- LIMIT 1
-- ;


   --这下面是为了检查我的想法是否是对的，下面代码是上面代码的解释，上面代码是简略的
-- select customer_number from
-- (select customer_number,count(*) from orders group by customer_number order by count(*) desc) as temp
-- limit 1;


   --这下面的是为了测试分组到底是怎么分的
-- select * from orders group by customer_number order by count(*) desc;
-- @lc code=end

