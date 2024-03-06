--
-- @lc app=leetcode.cn id=602 lang=mysql
--
-- [602] 好友申请 II ：谁有最多的好友
--

-- @lc code=start
# Write your MySQL query statement below
-- select accepter_id as id1, count(*) as num1 from RequestAccepted group by accepter_id
-- select requester_id as id2, count(*) as num2 from RequestAccepted group by requester_id

-- select l1.id1 as id, (l1.num1 + l2.num2)  from
-- (select accepter_id as id1, count(*) as num1 from RequestAccepted group by accepter_id) as l1
-- inner join
-- (select requester_id as id2, count(*) as num2 from RequestAccepted group by requester_id) as l2
-- on l1.id1 = l2.id2 order by (l1.num1 + l2.num2) desc limit 1;


-- with
-- l1 as
-- (select accepter_id as id1, count(*) as num1 from RequestAccepted group by accepter_id)
-- l2 as
-- (select requester_id as id2, count(*) as num2 from RequestAccepted group by requester_id)
-- l3 as
-- (select l1.id1 as id3, (l1.num1 + l2.num2) as num3 from
-- l1 inner join l2
-- on l1.id1 = l2.id2 order by (l1.num1 + l2.num2) desc limit 1)



select ids as id, cnt as num
from
(
select ids, count(*) as cnt
   from
   (
        select requester_id as ids from RequestAccepted
        union all
        select accepter_id from RequestAccepted
    ) as tbl1
   group by ids
   ) as tbl2
order by cnt desc
limit 1;
-- @lc code=end

