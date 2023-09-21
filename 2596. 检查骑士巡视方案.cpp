/*骑士在一张 n x n 的棋盘上巡视。在有效的巡视方案中，骑士会从棋盘的 左上角 出发，并且访问棋盘上的每个格子 恰好一次 。

给你一个 n x n 的整数矩阵 grid ，由范围 [0, n * n - 1] 内的不同整数组成，其中 grid[row][col] 表示单元格 (row, col) 是骑士访问的第 grid[row][col] 个单元格。骑士的行动是从下标 0 开始的。

如果 grid 表示了骑士的有效巡视方案，返回 true；否则返回 false。

注意，骑士行动时可以垂直移动两个格子且水平移动一个格子，或水平移动两个格子且垂直移动一个格子。*/
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){
          return false;
        }
        int n=grid.size();
        vector<vector<int>>cnt(n*n,vector<int>(2));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
              cnt[grid[i][j]]={i,j};
            }
        }
        for(int i=1;i<cnt.size();++i){
          int dx=abs(cnt[i][0]-cnt[i-1][0]);
          int dy=abs(cnt[i][1]-cnt[i-1][1]);
          if(dx*dy!=2){
              return false;
          }
        }
        return true;
    }
};