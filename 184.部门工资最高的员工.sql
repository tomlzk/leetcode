--
-- @lc app=leetcode.cn id=184 lang=mysql
--
-- [184] 部门工资最高的员工
--

-- @lc code=start
# Write your MySQL query statement below
-- select Department.name as Department, E.name as Employee, E.salary as salary from 
-- (select l2.name, max(salary) as salary, l2.departmentId from 
-- Employee group by departmentId, Employee as l2 having id = l2.id)
--  as E inner join Department on E.departmentId = Department.id;

-- SELECT Department.name as Department, E.name as Employee, E.salary as salary 
-- FROM (
--     SELECT l2.name, MAX(l2.salary) as salary, l2.departmentId 
--     FROM Employee as l2 
--     GROUP BY l2.departmentId, l2.name
-- ) as E 
-- INNER JOIN Department ON E.departmentId = Department.id;

-- select name as Department, Employee.name as Employee, Employee.salary as salary from
-- (Employee left join Department on Employee.departmentId = Department.id) group by departmentId limit 1;

SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
    )
;

-- SELECT
--     Department.name AS 'Department',
--     Employee.name AS 'Employee',
--     Salary
-- FROM
--     Employee
--         JOIN
--     Department ON Employee.DepartmentId = Department.Id
-- WHERE
--     (Employee.DepartmentId , Salary) IN
--     (   SELECT
--             DepartmentId, MAX(Salary)
--         FROM
--             Employee
--         GROUP BY DepartmentId
--     )
-- ;

-- @lc code=end

