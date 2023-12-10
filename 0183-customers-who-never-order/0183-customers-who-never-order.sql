/* Write your T-SQL query statement below */
select 
    customers.name as customers  from customers
        left join orders on customers.id=orders.customerId  
        where orders.id IS NULL;