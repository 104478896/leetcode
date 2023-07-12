/*表: Person

+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| email       | varchar |
+-------------+---------+
id是该表的主键列。
该表的每一行包含一封电子邮件。电子邮件将不包含大写字母。
 

编写一个 SQL 删除语句来 删除 所有重复的电子邮件，只保留一个id最小的唯一电子邮件。

以 任意顺序 返回结果表。 （注意： 仅需要写删除语句，将自动对剩余结果进行查询）

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/delete-duplicate-emails
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*# Write your MySQL query statement below*/
delete p1 from Person p1,
    Person p2
    where p1.email = p2.email and p1.id>p2.id;