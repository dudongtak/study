select
year(e.DIFFERENTIATION_DATE) as year,
(select MAX(size_of_colony) 
 from ecoli_data 
 where year(DIFFERENTIATION_DATE)=year) - e.size_of_colony as year_dev,
e.id
from ecoli_data e
order by year, year_dev