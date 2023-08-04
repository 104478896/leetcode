/*在二维网格 grid 上，有 4 种类型的方格：

1 表示起始方格。且只有一个起始方格。
2 表示结束方格，且只有一个结束方格。
0 表示我们可以走过的空方格。
-1 表示我们无法跨越的障碍。
返回在四个方向（上、下、左、右）上行走时，从起始方格到结束方格的不同路径的数目。

每一个无障碍方格都要通过一次，但是一条路径中不能重复通过同一个方格。*/
class Solution {
public:
    int dfs(vector<vector<int>>&grid,int x,int y,int agree){
        if(x<0||y<0||x>=grid.size()||y>=grid[0].size()||grid[x][y]==-1){
            return 0;
        }
        if(grid[x][y]==2){
            return agree==0?1:0;
        }
        grid[x][y]=-1;//查找点置为已走
        int sum=dfs(grid,x,y-1,agree-1)+dfs(grid,x,y+1,agree-1)
                +dfs(grid,x-1,y,agree-1)+dfs(grid,x+1,y,agree-1);
        grid[x][y]=0;
        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX=-1;
        int startY=-1;
        int row=grid.size();
        int col=grid[0].size();
        int agree=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==1){
                    startX=i;
                    startY=j;
                }else if(grid[i][j]==0){
                    agree++;
                }
            }
        }
        int ans=dfs(grid,startX,startY,agree+1);
        return ans;
    }
};