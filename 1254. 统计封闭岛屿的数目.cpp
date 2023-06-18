/*二维矩阵 grid 由 0 （土地）和 1 （水）组成。岛是由最大的4个方向连通的 0 组成的群，封闭岛是一个 完全 由1包围（左、上、右、下）的岛。

请返回 封闭岛屿 的数目。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-closed-islands
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y){
        if(x<0 || y<0||x>=grid.size()||y>=grid[x].size()||grid[x][y]){
            return;
        }
        grid[x][y]=1;//将以访问元素置为1，避免重复访问
        dfs(grid,x-1,y);
        dfs(grid,x+1,y);
        dfs(grid,x,y-1);
        dfs(grid,x,y+1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        if(row<3||col<3){//当行数或列数小于3时，无论如何都不会形成封闭岛屿
            return 0;
        }
        for(int i=0;i<row;++i){//访问外围数值，从外围向内部访问，将不封闭的岛屿置为1，即排除
            int step=col-1;
            if(i==0||i==row-1){
                //访问外围，i为行，当行数为第一行或最后一行时，需要访问整行，
                //其余行方位第一列和最后一列
                step=1;
            }
            // cout<<"step:"<<step<<endl;
            for(int j=0;j<col;j+=step){
                dfs(grid,i,j);
            }
        }
        
        int ans=0;//ans为封闭岛屿的数
        //循环遍历内部，如果当前的值为0，必定为封闭岛屿，将整个封闭岛屿的所属置为1，代表以访问
        for(int i=1;i<row-1;++i){

            for(int j=1;j<col-1;++j){
                if(grid[i][j]==0){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};