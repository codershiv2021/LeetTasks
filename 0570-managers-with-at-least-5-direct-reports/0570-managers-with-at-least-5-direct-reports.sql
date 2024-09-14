SELECT name from Employee JOIN
(SELECT managerId from Employee group by managerID having 
count(managerId)>=5) as t1
where Employee.id = t1.managerId
