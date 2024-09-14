SELECT Employee.name,Bonus.bonus from Employee 
LEFT OUTER JOIN Bonus on (Employee.empId=Bonus.empId) 
where Bonus.bonus<1000 or Bonus.bonus IS NULL
