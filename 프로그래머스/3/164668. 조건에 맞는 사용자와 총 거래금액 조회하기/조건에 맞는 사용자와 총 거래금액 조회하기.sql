SELECT
b.writer_id as user_id,
u.nickname as nickname,
sum(b.price) as total_sales
from USED_GOODS_USER u, USED_GOODS_BOARD b
where b.STATUS='DONE'and b.writer_id=u.user_id
group by b.writer_id,u.nickname having total_sales >=700000
order by total_sales