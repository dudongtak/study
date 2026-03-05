with 2021_user as(
    select
        user_id
    from user_info
    where year(joined)=2021
)
SELECT
    year(o.sales_date) as year,
    month(o.sales_date) as month,
    count(distinct o.user_id) as purchased_users,
    round(count(distinct o.user_id)/(select count(*) from 2021_user),1) as puchased_ratio
from online_sale as o
join 2021_user as u on u.user_id=o.user_id
group by year,month
order by year,month