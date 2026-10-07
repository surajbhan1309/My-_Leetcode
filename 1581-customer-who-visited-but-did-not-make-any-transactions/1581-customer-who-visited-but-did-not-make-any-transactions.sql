# Write your MySQL query statement below
select v.customer_id,COUNT(v.customer_id) as count_no_trans
from Visits v
left join Transactions t
using (visit_id)
where t.Transaction_id is NULL
group by customer_id
