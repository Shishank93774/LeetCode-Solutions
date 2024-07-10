# Write your MySQL query statement below
SELECT name, bonus
FROM Employee AS e
LEFT JOIN Bonus AS b
ON e.empId = b.empID
WHERE b.empID IS NULL OR bonus < 1000;