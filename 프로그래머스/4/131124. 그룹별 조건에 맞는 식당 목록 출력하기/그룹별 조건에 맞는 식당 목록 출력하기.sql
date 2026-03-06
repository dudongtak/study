with cnt as(
select 
    count(r.member_id) as num,
    r.member_id,
    p.member_name
from rest_review as r
join member_profile as p on r.member_id=p.member_id
group by member_id
),
max_num as(
select
    max(num) as m
from cnt
)

select
    c.member_name,
    r.review_text,
    date_format(r.review_date,'%Y-%m-%d') as review_date
from rest_review as r
join cnt as c on c.member_id=r.member_id
join max_num as m on m.m=c.num
order by r.review_date,r.review_text