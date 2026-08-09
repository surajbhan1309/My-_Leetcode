# Write your MySQL query statement below
select e2.employee_id,e2.name,
COUNT(e1.employee_id) as reports_count,
ROUND(AVG(e1.age)) as average_age 
from Employees e1
join  Employees e2
on e1.reports_to=e2.employee_id
GROUP BY e2.employee_id, e2.name
order by e2.employee_id