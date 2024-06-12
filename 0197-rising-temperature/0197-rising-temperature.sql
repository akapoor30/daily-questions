# Write your MySQL query statement below
select w1.id from weather w1 join weather w2 on w1.temperature > w2.temperature where
datediff(w1.recordDate,w2.recordDate)=1 ;