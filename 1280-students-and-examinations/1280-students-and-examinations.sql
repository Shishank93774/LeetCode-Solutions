SELECT t.student_id, t.student_name, t.subject_name,
COALESCE(
    (
        SELECT COUNT(*)
        FROM examinations e
        WHERE t.student_id = e.student_id AND t.subject_name = e.subject_name 
        GROUP BY e.student_id, e.subject_name
    ), 0
) AS attended_exams
FROM (
    SELECT s.student_id, s.student_name, sub.subject_name
    FROM students s, subjects sub
) AS t
ORDER BY t.student_id, t.subject_name;
