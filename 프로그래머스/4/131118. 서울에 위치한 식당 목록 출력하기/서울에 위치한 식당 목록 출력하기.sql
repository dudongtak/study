-- 코드를 입력하세요
SELECT
    i.rest_id as rest_id,
    i.rest_name as rest_name,
    i.food_type as food_type,
    i.favorites as favorites,
    i.address as address,
    round(avg(r.review_score),2) as score
from rest_info i
join rest_review r on i.rest_id=r.rest_id
group by i.rest_id
having i.address like '서울%'
order by score desc, favorites desc;