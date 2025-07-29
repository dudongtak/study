-- 코드를 입력하세요
SELECT
    b.category,
    sum(s.sales) as total_sales
from book b,book_sales s
where year(s.sales_date)='2022' and month(s.sales_date)='01' and b.book_id=s.book_id
group by b.category
order by category 