# Write your MySQL query statement below
SELECT q.person_name 
FROM Queue q 
WHERE ( 
SELECT SUM(q2.weight) 
FROM Queue q2 
WHERE q2.turn <= q.turn 
) <= 1000 
ORDER BY q.turn DESC 
LIMIT 1; 