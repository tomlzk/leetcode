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

-- SELECT
--     Department.name AS 'Department',
--     Employee.name AS 'Employee',
--     Employee.Salary
-- FROM
--     Employee
--         JOIN
--     Department ON Employee.DepartmentId = Department.Id
-- WHERE
--     (Employee.DepartmentId , Employee.Salary) IN
--     (   SELECT
--             E1.DepartmentId, E1.Salary
--         FROM
--             Employee AS E1
--         LEFT JOIN Employee AS E2 ON E1.DepartmentId = E2.DepartmentId AND E1.Salary < E2.Salary
--         WHERE
--             E2.Salary IS NULL
--     );

-- SELECT
--     Department.name AS 'Department',
--     Employee.name AS 'Employee',
--     Employee.Salary
-- FROM
--     Employee
--         JOIN
--     Department ON Employee.DepartmentId = Department.Id
-- WHERE
--     (Employee.DepartmentId , Employee.Salary) IN
--     (   SELECT
--             E1.DepartmentId, E1.Salary
--         FROM
--             (select
--             Employee.DepartmentId,
--              case @i
--                when @i < @j then @i := @j
--                else 
--              end as Salary,
--              @j := Employee.salary
--              from
--              Employee
--              (select @i := 0, @j := 0)
--              ;
--              )
--     );

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

-- SELECT
--     Department.name AS 'Department',
--     Employee.name AS 'Employee',
--     Employee.Salary
-- FROM
--     Employee
--     JOIN Department ON Employee.DepartmentId = Department.Id
-- WHERE
--     (Employee.DepartmentId, Employee.Salary) IN 
--     (
--         SELECT
--             t.DepartmentId,
--             t.Salary
--         FROM
--             (
--                 SELECT
--                     --@department_id := Employee.DepartmentId,
--                     Employee.DepartmentId,
--                     CASE
--                         WHEN @department_id = Employee.DepartmentId THEN
--                             CASE
--                                 WHEN @salary < Employee.Salary THEN @salary := Employee.Salary
--                                 ELSE @salary := @salary
--                             END
--                         ELSE @salary := Employee.Salary
--                     END AS Salary,
--                     @department_id := Employee.DepartmentId
--                 FROM
--                     (select @department_id := -1, @salary := -1) as b,
--                     Employee
--                 ORDER BY
--                     Employee.DepartmentId,
--                     Employee.Salary DESC
--             ) AS t
--         WHERE
--             t.Salary IS NOT NULL
--     );

SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Employee.Salary
FROM
    Employee
    JOIN Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId, Employee.Salary) IN 
    (
        SELECT
            t.DepartmentId,
            t.Salary
        FROM
            (
                SELECT
                    Employee.DepartmentId,
                    if( @department_id = Employee.DepartmentId,  
                        if(@salary < Employee.Salary,@salary := Employee.Salary,@salary),
                        @salary := Employee.Salary) AS Salary,
                    @department_id := Employee.DepartmentId
                FROM
                    (select @department_id := -1, @salary := -1) as b,
                    Employee
                ORDER BY
                    Employee.DepartmentId,
                    Employee.Salary DESC
            ) AS t
        WHERE
            t.Salary IS NOT NULL
    );

-- SELECT
--     Department.name AS 'Department',
--     Employee.name AS 'Employee',
--     Employee.Salary
-- FROM
--     Employee
--     JOIN Department ON Employee.DepartmentId = Department.Id
-- WHERE
--     (Employee.DepartmentId, Employee.Salary) IN (
--         SELECT
--             t.DepartmentId,
--             t.Salary
--         FROM
--             (
--                 SELECT
--                     Employee.DepartmentId,
--                     CASE
--                         WHEN @department_id = Employee.DepartmentId THEN
--                             CASE
--                                 WHEN @salary < Employee.Salary THEN @salary := Employee.Salary
--                                 ELSE @salary
--                             END
--                         ELSE @salary := Employee.Salary
--                     END AS Salary,
--                     @department_id := Employee.DepartmentId
--                 FROM
--                     (select @department_id := -1, @salary := -1) as b,
--                     Employee
--                 ORDER BY
--                     Employee.DepartmentId,
--                     Employee.Salary DESC
--             ) AS t
--         WHERE
--             t.Salary IS NOT NULL
--     );


-- @lc code=end

