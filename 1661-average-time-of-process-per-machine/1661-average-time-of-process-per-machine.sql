# Write your MySQL query statement below
SELECT A.machine_id, ROUND(((
                        SELECT SUM(timestamp)
                        FROM Activity AS A_
                        WHERE A_.machine_id = A.machine_id AND activity_type = 'end'
                    )
                    -
                    (
                        SELECT SUM(timestamp)
                        FROM Activity AS A_
                        WHERE A_.machine_id = A.machine_id AND activity_type = 'start'
                    )
                      )
                    /
                    (
                        SELECT COUNT(machine_id)
                        FROM Activity AS A_
                        WHERE A_.machine_id = A.machine_id AND activity_type = 'end'
                    ), 3)
                    AS processing_time
FROM Activity AS A
GROUP BY A.machine_id;
