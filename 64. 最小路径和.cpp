/*给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(i==0&&j==0){
                    continue;
                }else if(j==0){
                    grid[i][j]=grid[i-1][j]+grid[i][j];
                }else if(i==0){
                    grid[i][j]=grid[i][j-1]+grid[i][j];
                }else{
                    grid[i][j]=min(grid[i-1][j],grid[i][j-1])+grid[i][j];
                }
            }
        }
        return grid[row-1][col-1];
    }
};