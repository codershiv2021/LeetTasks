SELECT contest_id,ROUND(100*count(contest_id)/(SELECT count(*)from Users),2) as percentage
from Register group by contest_id
order by percentage desc, contest_id
