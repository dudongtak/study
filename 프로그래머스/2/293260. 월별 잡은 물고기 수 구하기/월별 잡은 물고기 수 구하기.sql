-- 코드를 작성해주세요
select
    count(fish_type) as fish_count,
    month(time) as month
from fish_info
group by month
order by month