# Write your MySQL query statement below
SELECT V.customer_id, COUNT(V.customer_id) AS count_no_trans
FROM Visits AS V
WHERE V.visit_id NOT IN (
                            SELECT T.visit_id
                            FROM Transactions AS T
                            )
GROUP BY V.customer_id;
