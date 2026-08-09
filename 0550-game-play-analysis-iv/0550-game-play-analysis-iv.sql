# Write your MySQL query statement below
select ROUND(COUNT(distinct player_id)/(select COUNT(distinct player_id) from Activity),2)
as fraction
from Activity
where (player_id,DATE_SUB(event_date,INTERVAl 1 DAY)) in (
    select player_id,MIN(event_date)
    from Activity
    group by player_id
)