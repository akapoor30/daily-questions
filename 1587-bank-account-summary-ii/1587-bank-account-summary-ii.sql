/* Write your T-SQL query statement below */
select 
   Users.name ,sum(Transactions.amount) as balance 
from 
    Users 
inner join  
    Transactions 
on 
    Users.account=Transactions.account 
group by 
    Users.name,Users.account 
having 
    sum(amount)>10000;