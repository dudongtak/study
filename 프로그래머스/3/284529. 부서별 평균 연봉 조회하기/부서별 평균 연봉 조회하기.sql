-- 코드를 작성해주세요
select
    d.dept_id as dept_id,
    d.dept_name_en as dept_name_en,
    round(avg(e.sal)) as avg_sal
from HR_DEPARTMENT d
join HR_EMPLOYEES e on e.dept_id=d.dept_id
group by dept_id
order by avg_sal desc