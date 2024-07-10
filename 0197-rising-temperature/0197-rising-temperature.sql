# Write your MySQL query statement below
SELECT W1.id
FROM Weather AS W1
JOIN Weather AS W2
WHERE W1.temperature > W2.temperature AND (W2.recordDate = DATE_SUB(W1.recordDate, INTERVAL 1 DAY));