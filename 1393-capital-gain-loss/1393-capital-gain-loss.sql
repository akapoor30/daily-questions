/* Write your T-SQL query statement below */
select s.stock_name , sum(case when operation='Buy' then s.price*(-1) else s.price end) as capital_gain_loss from Stocks s group by stock_name;