-- 코드를 입력하세요
SELECT
    a.author_id as author_id,
    a.author_name as author_name,
    b.category as category,
    sum(b.price * s.sales) as total_sales
from book_sales s
join book b on s.book_id=b.book_id
join author a on b.author_id=a.author_id
where year(s.sales_date)=2022 and month(s.sales_date)=1
group by b.category, a.author_id
order by a.author_id, b.category desc