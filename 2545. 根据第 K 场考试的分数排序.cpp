/*班里有 m 位学生，共计划组织 n 场考试。给你一个下标从 0 开始、大小为 m x n 的整数矩阵 score ，其中每一行对应一位学生，而 score[i][j] 表示第 i 位学生在第 j 场考试取得的分数。矩阵 score 包含的整数 互不相同 。

另给你一个整数 k 。请你按第 k 场考试分数从高到低完成对这些学生（矩阵中的行）的排序。

返回排序后的矩阵。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sort-the-students-by-their-kth-score
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    //sort函数排序，根据数组中的指定第k词考试的结果为参数进行排序
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        sort(score.begin(),score.end(),[k](vector<int>a,vector<int>b){
            return a[k]>b[k];
        });

        return score;
    }
};