select e1.name as Employee
from employee e1, employee e2
where e1.ManagerId is not NULL
and e1.managerId = e2.id and e1.salary > e2.salary