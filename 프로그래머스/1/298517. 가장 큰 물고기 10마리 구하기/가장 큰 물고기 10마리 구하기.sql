select
id,length
from fish_info
where length>=10
order by length desc,id
limit 10