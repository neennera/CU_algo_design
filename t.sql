SELECT 
    o.order_id AS OrderID, 
    a.username AS CustomerUsername, 
    cr.course_name AS CourseName, 
    p.prophet_method AS ProphetMethod, 
    o.timestamp AS OrderDate
FROM ordert o
JOIN customer c ON o.customer_id = c.customer_id
JOIN account a ON c.customer_id = a.account_id
JOIN course cr ON o.course_id = cr.course_id
JOIN prophet p ON cr.prophet_id = p.prophet_id
WHERE (o.timestamp BETWEEN '2024-01-01' AND '2024-01-31 23:59') AND (o.status = 'SUCCESS')
ORDER BY orderdate
