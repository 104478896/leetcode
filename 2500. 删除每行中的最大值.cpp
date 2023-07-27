/*给你一个 m x n 大小的矩阵 grid ，由若干正整数组成。

执行下述操作，直到 grid 变为空矩阵：

从每一行删除值最大的元素。如果存在多个这样的值，删除其中任何一个。
将删除元素中的最大值与答案相加。
注意 每执行一次操作，矩阵中列的数据就会减 1 。

返回执行上述操作后的答案。*/
class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int sum=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;++i){
            sort(grid[i].begin(),grid[i].end());
        }
        
        for(int i=col-1;i>=0;--i){
            int temp=0;
            for(int j=0;j<row;++j){
                temp=max(temp,grid[j][i]);
            }
            sum+=temp;
        }
        return sum;
    }
};