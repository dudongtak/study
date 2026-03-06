with food as(
select 
    product_id,
    sum(amount) as amount
from food_order
where year(produce_date)=2022 and month(produce_date)=5
group by product_id
)

select 
    f.product_id,
    p.product_name,
    f.amount*p.price as total_sales
from food as f
join food_product as p on f.product_id=p.product_id
order by f.amount*p.price desc,f.product_id