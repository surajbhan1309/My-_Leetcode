# Write your MySQL query statement below
select e_uni.unique_id,e.name from Employees e
left join EmployeeUNI e_uni
on e.id=e_uni.id
