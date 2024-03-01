--
-- @lc app=leetcode.cn id=180 lang=mysql
--
-- [180] 连续出现的数字
--

-- @lc code=start
# Write your MySQL query statement below
SELECT
    DISTINCT t.Num AS ConsecutiveNums
FROM
(
SELECT 
    CASE @pre WHEN Num THEN 
        @cnt := @cnt + 1
    ELSE @cnt := 1 END AS cnt,
    @pre := Num,
    Num
FROM
    Logs a,
    (SELECT @cnt := 1, @pre := '') b
) t WHERE t.cnt >= 3
-- @lc code=end

