select distinct
    d.id,
    d.email,
    d.first_name,
    d.last_name
#from developers d, skillcodes s
#where (s.name='C#' or s.name='Python')and s.code&d.skill_code=s.code
from developers d
join skillcodes s
on (s.name='C#' or s.name='Python') and s.code&d.skill_code=s.code
order by id