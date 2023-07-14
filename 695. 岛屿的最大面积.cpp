/*给你一个大小为 m x n 的二进制矩阵 grid 。

岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在 水平或者竖直的四个方向上 相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

岛屿的面积是岛上值为 1 的单元格的数目。

计算并返回 grid 中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/max-area-of-island
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int dfs(vector<vector<int>>& grid,int x,int y){
        if(x<0||y<0||x>grid.size()-1||y>grid[0].size()-1||grid[x][y]==0){
            return 0;
        }
        
        grid[x][y]=0;
        int ans=1;
        ans+=dfs(grid,x-1,y);
        ans+=dfs(grid,x+1,y);
        ans+=dfs(grid,x,y-1);
        ans+=dfs(grid,x,y+1);
        return ans;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                res=max(res,dfs(grid,i,j));
            }
        }
        return res;
    }
};
