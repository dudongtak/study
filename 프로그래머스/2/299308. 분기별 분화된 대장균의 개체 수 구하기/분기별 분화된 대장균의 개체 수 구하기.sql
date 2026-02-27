-- 코드를 작성해주세요
select 
    case
        when month(DIFFERENTIATION_DATE) between 1 and 3 then '1Q'
        when month(DIFFERENTIATION_DATE) between 4 and 6 then '2Q'
        when month(DIFFERENTIATION_DATE) between 7 and 9 then '3Q'
        else '4Q'
    end as quarter,
    count(*) as ecoli_count 
from ecoli_data 
group by quarter
order by quarter