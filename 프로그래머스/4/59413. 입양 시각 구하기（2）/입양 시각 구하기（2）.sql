-- 코드를 입력하세요
with recursive hour as(
    select 0 as level
    union all
    select 1+hour.level
    from hour
    where hour.level <23
)
select h.level as hour, count(o.datetime)
from hour h
left join animal_outs o on h.level=hour(o.datetime)
group by h.level
order by h.level