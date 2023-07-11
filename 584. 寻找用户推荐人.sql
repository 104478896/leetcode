/*给定表 customer ，里面保存了所有客户信息和他们的推荐人。

+------+------+-----------+
| id   | name | referee_id|
+------+------+-----------+
|    1 | Will |      NULL |
|    2 | Jane |      NULL |
|    3 | Alex |         2 |
|    4 | Bill |      NULL |
|    5 | Zack |         1 |
|    6 | Mark |         2 |
+------+------+-----------+
写一个查询语句，返回一个客户列表，列表中客户的推荐人的编号都 不是 2。
避免错误的秘诀在于使用 IS NULL 或者 IS NOT NULL 两种操作来对 NULL 值做特殊判断。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-customer-referee
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/*# Write your MySQL query statement below*/
select name from customer where referee_id != 2 or referee_id is NULL