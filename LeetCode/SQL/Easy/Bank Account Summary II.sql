select e1.name, sum(e2.amount) as balance
from users as e1
join transactions e2
on e1.account = e2.account
group by e1.account
having balance > 10000