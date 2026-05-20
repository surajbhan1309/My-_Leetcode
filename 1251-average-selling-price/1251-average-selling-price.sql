# Write your MySQL query statement below
select p.product_id,ifnull(ROUND(SUM(units*price)/SUM(units),2),0) as average_price
from Prices p 
Left JOin UnitsSold u
On p.product_id=u.product_id 
and 
u.purchase_date BETWEEN start_date 
and 
end_date
group by product_id 