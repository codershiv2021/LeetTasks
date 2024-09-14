SELECT t1.student_id as student_id,t1.student_name as student_name
,t2.subject_name as subject_name,
count(t3.subject_name) as attended_exams
from 
Students as t1 JOIN Subjects as t2
LEFT JOIN Examinations as t3
on (t1.student_id=t3.student_id AND t2.subject_name=t3.subject_name)
group by t1.student_id,t2.subject_name
order by t1.student_id,t2.subject_name;
-- () mat use karna in group by or select wherever needed vaha hi 

-- ye upar vala when only give values of jinkhone attend kiya unka count
-- if want ki jo not attended voh ka bhi hm de toh left join