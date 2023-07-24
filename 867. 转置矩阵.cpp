/*给你一个二维整数数组 matrix， 返回 matrix 的 转置矩阵 。

矩阵的 转置 是指将矩阵的主对角线翻转，交换矩阵的行索引与列索引。*/
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>ans(col,vector<int>(row));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                ans[j][i]=matrix[i][j];
            }
        }
        return ans;
    }
};