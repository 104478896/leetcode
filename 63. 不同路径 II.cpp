/*一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 1 和 0 来表示。*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row=obstacleGrid.size();
        int col=obstacleGrid[0].size();
        vector<int>dp(col);
        dp[0]=obstacleGrid[0][0]==0?1:0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(obstacleGrid[i][j]==1){
                    dp[j]=0;
                }else if(j>=1&&obstacleGrid[i][j]==0){
                    dp[j]+=dp[j-1];
                }
                
            }
        }
        return dp[col-1];
    }
};