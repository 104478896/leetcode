/*给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    void dfs(vector<vector<char>>&grid,int x,int y){
        if(x<0||x>grid.size()||y<0||y>grid[x].size()){
            return ;
        }
        grid[x][y]='0';
        if(x>=1&&grid[x-1][y]=='1'){
            dfs(grid,x-1,y);
        }
        if(x<grid.size()-1&&grid[x+1][y]=='1'){
            dfs(grid,x+1,y);
        }
        if(y>=1&&grid[x][y-1]=='1'){
            dfs(grid,x,y-1);
        }
        if(y<grid[x].size()-1&&grid[x][y+1]=='1'){
            dfs(grid,x,y+1);
        }
             
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};