# Write your MySQL query statement below

SELECT
    request_at AS Day,
    ROUND(
        SUM(CASE
            WHEN status != 'completed' THEN 1
            ELSE 0
        END) / COUNT(*),
        2
    ) AS 'Cancellation Rate'
FROM Trips t
JOIN Users u
ON t.client_id = u.users_id
JOIN Users d
ON t.driver_id = d.users_id
WHERE u.banned = 'No'
AND d.banned = 'No'
AND request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY request_at;
