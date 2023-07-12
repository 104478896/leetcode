/*Salary 表：

+-------------+----------+
| Column Name | Type     |
+-------------+----------+
| id          | int      |
| name        | varchar  |
| sex         | ENUM     |
| salary      | int      |
+-------------+----------+
id 是这个表的主键。
sex 这一列的值是 ENUM 类型，只能从 ('m', 'f') 中取。
本表包含公司雇员的信息。
 

请你编写一个 SQL 查询来交换所有的 'f' 和 'm' （即，将所有 'f' 变为 'm' ，反之亦然），仅使用 单个 update 语句 ，且不产生中间临时表。

注意，你必须仅使用一条 update 语句，且 不能 使用 select 语句。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/swap-salary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*# Write your MySQL query statement below*/
update Salary 
    set 
        sex = case sex 
                when 'm' then 'f'
                else 'm'
            end