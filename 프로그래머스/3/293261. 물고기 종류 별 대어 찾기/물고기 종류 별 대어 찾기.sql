with max_l as(
select
    fish_type,
    max(length) as length
from fish_info
group by fish_type
)
select
    i.id,
    n.fish_name,
    m.length
from fish_info as i
join fish_name_info as n on i.fish_type=n.fish_type
join max_l as m on m.fish_type=i.fish_type and m.length=i.length
order by i.id