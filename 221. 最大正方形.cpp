/*在一个由 '0' 和 '1' 组成的二维矩阵内，找到只包含 '1' 的最大正方形，并返回其面积。

 */
 class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxSide=0;
        int row=matrix.size();
        int col=matrix[0].size();
        if(row==0||col==0){
            return 0;
        }
        vector<vector<int>>dp(row,vector<int>(col));
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(matrix[i][j]=='1'){
                    if(i==0||j==0){
                        dp[i][j]=1;
                    }else{
                        dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                    }
                    maxSide=max(maxSide,dp[i][j]);
                }
                
            }
        }
        return maxSide*maxSide;
    }
};