# Write your MySQL query statement below
select p.product_id,
COALESCE((select pr.new_price
        from products pr
        where p.product_id=pr.product_id
        and pr.change_date<='2019-08-16'
        order by pr.change_date desc limit 1
        ),10) as price
from (select distinct product_id
        from products
    ) as p