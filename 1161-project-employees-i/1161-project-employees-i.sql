SELECT project_id, ROUND(avg(experience_years),2) as average_years from
Project JOIN Employee where (Project.employee_id = Employee.employee_id)
group by project_id 
