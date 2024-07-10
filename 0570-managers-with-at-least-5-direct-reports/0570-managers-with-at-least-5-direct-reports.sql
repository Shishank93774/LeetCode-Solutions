# Write your MySQL query statement below
SELECT e.name
FROM Employee AS e
WHERE (
    SELECT COUNT(*)
    FROM Employee AS e_
    WHERE e.id = e_.managerId
    GROUP BY e_.managerId
) > 4;