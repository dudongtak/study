select
    m.cart_id
from(
    select
        cart_id
    from cart_products
    where name='Milk'
    ) as m
join (select
    cart_id
from cart_products
where name='Yogurt') as y on y.cart_id=m.cart_id
order by m.cart_id