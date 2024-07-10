# Write your MySQL query statement below
SELECT id
FROM Weather as W1
WHERE W1.temperature > (
                    SELECT W2.temperature
                    FROM Weather AS W2
                    WHERE W2.recordDate = DATE_SUB(W1.recordDate, INTERVAL 1 DAY)
                    );