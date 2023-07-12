/*表: Employees

+-------------+---------+
| 列名        | 类型     |
+-------------+---------+
| employee_id | int     |
| name        | varchar |
| salary      | int     |
+-------------+---------+
employee_id 是这个表的主键。
此表的每一行给出了雇员id ，名字和薪水。
 

写出一个SQL 查询语句，计算每个雇员的奖金。如果一个雇员的id是奇数并且他的名字不是以'M'开头，那么他的奖金是他工资的100%，否则奖金为0。

Return the result table ordered by employee_id.

返回的结果集请按照employee_id排序。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/calculate-special-bonus
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*# Write your MySQL query statement below*/
select 
    employee_id,if 
        (employee_id%2=1 and name not like 'M%',
        salary,
        0) 
        as bonus 
from employees
order by employee_id