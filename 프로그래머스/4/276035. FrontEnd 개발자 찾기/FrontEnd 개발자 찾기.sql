with front as(
select
    code
from skillcodes
where category='Front End'
)

select distinct
    d.id,
    d.email,
    d.first_name,
    d.last_name
from developers as d
join front as f on d.skill_code&f.code=f.code
order by d.id