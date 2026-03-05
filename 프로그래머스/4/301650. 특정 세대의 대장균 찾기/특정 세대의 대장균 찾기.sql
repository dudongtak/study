with RECURSIVE g3(id,parent_id,generation)as(
    select id,parent_id,1 from ECOLI_DATA where parent_id is null
    union all
    select
        e.id,
        e.parent_id,
        g.generation+1
    from g3 as g
    join ECOLI_DATA as e on e.parent_id=g.id
)
select id from g3 where generation=3 order by id