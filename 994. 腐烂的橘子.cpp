/*在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

值 0 代表空单元格；
值 1 代表新鲜橘子；
值 2 代表腐烂的橘子。
每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/rotting-oranges
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<pair<int,int>>que;//存储腐烂橘子，即起始点
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==2){
                    que.push({i,j});
                }
            }
        }
        int ans=0;//全部腐烂所需时间
        int dirs[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
        while(!que.empty()){
            int len=que.size();//获取队列中腐烂橘子的数量，从每个起始点进行遍历
            for(int m=0;m<len;++m){
                int x=que.front().first;//起始点坐标
                int y=que.front().second;
                que.pop();//弹出已获取的起始点
                for(int i=0;i<4;++i){
                    int new_x=x+dirs[i][0];//新坐标
                    int new_y=y+dirs[i][1];
                    //新坐标在网格内，同时为新鲜橘子，可被腐烂
                    if(new_x>=0&&new_y>=0&&new_x<row&&new_y<col&&grid[new_x][new_y]==1){
                        grid[new_x][new_y]=2;//新鲜橘子被腐烂
                        que.push({new_x,new_y});//将该坐标作为新起始点存入队列
                    }    
                }
            }
            //如果在遍历完当次的队列之后，没有新的坐标被放入队列，
            //代表当次没有新鲜橘子被腐烂或已经没有新鲜橘子了，不需要增加时间，
            //否则需要增加时间代表被腐烂的橘子的这一分钟
            if(!que.empty()){
                ans++;
            }
            
        }

        //查看是否有新鲜橘子，有则表示无法被腐烂
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};