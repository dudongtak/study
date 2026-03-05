with truck as(
select
    car_id,
    daily_fee
from CAR_RENTAL_COMPANY_CAR
where car_type='트럭'
)
,discount as(
select 
    case
    when duration_type like '7%' then 7
    when duration_type like '30%' then 30
    else 90 end as duration,
    discount_rate as dis
from CAR_RENTAL_COMPANY_DISCOUNT_PLAN
where car_type='트럭'
)

SELECT
    h.history_id,
    (datediff(h.end_date,h.start_date)+1)*t.daily_fee*
    (100 - 
    case
        when (datediff(h.end_date,h.start_date)+1)>=90 then (select d.dis from discount as d where d.duration=90)
        when (datediff(h.end_date,h.start_date)+1)>=30 then (select d.dis from discount as d where d.duration=30)
        when (datediff(h.end_date,h.start_date)+1)>=7 then (select d.dis from discount as d where d.duration=7)
     else 0
     end
    )div 100
    as fee
from car_rental_company_rental_history as h
join truck as t on t.car_id=h.car_id
order by fee desc, history_id desc
    