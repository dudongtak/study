with ap as(
select
    apnt_ymd,
    apnt_no,
    pt_no,
    mcdp_cd,
    mddr_id
from appointment
where apnt_cncl_yn='N'and mcdp_cd='CS' and date_format(date(apnt_ymd),'%Y-%m-%d')='2022-04-13'
)

select
    a.apnt_no,
    p.pt_name,
    a.pt_no,
    a.mcdp_cd,
    d.dr_name,
    a.apnt_ymd
from ap as a
join patient as p on p.pt_no=a.pt_no
join doctor as d on d.dr_id=a.mddr_id
order by a.apnt_ymd