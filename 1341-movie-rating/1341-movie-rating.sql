# Write your MySQL query statement below
(select u.name as results from Users u
join MovieRating m using (user_id)
group by u.user_id,u.name
order by count(*) desc,name
limit 1)

union all 

(select title as results
from MovieRating 
join Movies using (movie_id)
where EXTRACT(YEAR_MONTH from created_at)=202002
group by title
order by AVG(rating) desc,title
limit 1)





