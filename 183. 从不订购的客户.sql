/*某网站包含两个表，Customers 表和 Orders 表。编写一个 SQL 查询，找出所有从不订购任何东西的客户。

Customers 表：

+----+-------+
| Id | Name  |
+----+-------+
| 1  | Joe   |
| 2  | Henry |
| 3  | Sam   |
| 4  | Max   |
+----+-------+
Orders 表：

+----+------------+
| Id | CustomerId |
+----+------------+
| 1  | 3          |
| 2  | 1          |
+----+------------+

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/customers-who-never-order
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*# Write your MySQL query statement below*/
select Name as Customers from Customers where Id not in (select CustomerId from Orders)