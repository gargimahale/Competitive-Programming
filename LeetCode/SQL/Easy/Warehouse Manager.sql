select name as warehouse_name, sum(units*width*length*height) as volume
from warehouse w
left join products p
on w.product_id = p.product_id
group by name