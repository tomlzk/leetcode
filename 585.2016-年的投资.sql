--
-- @lc app=leetcode.cn id=585 lang=mysql
--
-- [585] 2016年的投资
--

-- @lc code=start
# Write your MySQL query statement below
-- (select lat from Insurance group by lat having count(*) = 1) as l1;

-- (select * from l1 left join Insurance on l1.lat = Insurance.lat) as l2;

-- (select lon from l2 group by lon having count(*) = 1) as l3;

-- (select * from l3 left join Insurance on l3.lon - Insurance.lon) as 14

-- select sum(tiv_2016) from l4 group by tiv_2015 having count(*) > 1;

-- select sum(tiv_2016) as tiv_2016 from
-- (select sum(tiv_2016) as tiv_2016 from



-- (select pid, tiv_2015, tiv_2016, lat, l3.lon from


-- (select lon from

-- (select pid, tiv_2015, tiv_2016, l1.lat, lon from
-- (select lat from Insurance group by lat having count(*) = 1) as l1
-- left join Insurance on l1.lat = Insurance.lat) as l2

-- group by lon having count(*) = 1) as l3


-- left join Insurance on l3.lon = Insurance.lon) as l4



-- group by tiv_2015 having count(*) > 1) as l5;




SELECT
    round(SUM(insurance.TIV_2016), 2) AS TIV_2016
FROM
    insurance
WHERE
    insurance.TIV_2015 IN
    (
      SELECT
        TIV_2015
      FROM
        insurance
      GROUP BY TIV_2015
      HAVING COUNT(*) > 1
    )
    AND CONCAT(LAT, LON) IN
    (
      SELECT
        CONCAT(LAT, LON)
      FROM
        insurance
      GROUP BY LAT , LON
      HAVING COUNT(*) = 1
    )
;

-- @lc code=end

