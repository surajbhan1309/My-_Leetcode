# Write your MySQL query statement below
select user_id,
CONCAT(UPPER(SUBSTR(users.name,1,1)),LOWER(SUBSTR(users.name,2))) as name
from Users
order by user_id asc