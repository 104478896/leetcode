/*给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>row(m);
        vector<int>col(n);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }

        }
        
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(row[i]||col[j]){
                    matrix[i][j]=0;
                }
            }

        }
        
    }
};