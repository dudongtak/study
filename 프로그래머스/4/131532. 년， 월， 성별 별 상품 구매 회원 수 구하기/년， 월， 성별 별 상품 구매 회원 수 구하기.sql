-- 코드를 입력하세요
SELECT
    year(s.sales_date) as year,
    month(s.sales_date) as month,
    i.gender as gender,
    count(distinct s.user_id) as users
from online_sale s
join user_info i on s.user_id=i.user_id and gender is not null
group by year, month, gender
order by year, month, gender