select P.name, sum(I.rest) as rest, sum(I.paid) as paid, sum(I.canceled) as canceled, sum(I.refunded) as refunded
from Product P
right join Invoice I
on P.product_id = I.product_id
group by P.name
order by P.name