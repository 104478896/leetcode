/*给你一个大小为 m x n 的整数矩阵 grid 。

按以下形式将矩阵的一部分定义为一个 沙漏 ：


返回沙漏中元素的 最大 总和。

注意：沙漏无法旋转且必须整个包含在矩阵中。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-sum-of-an-hourglass
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int ans=0;
        for(int i=1;i<row-1;++i){
            for(int j=1;j<col-1;++j){
                ans=max(ans,grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i][j]+grid[i+1][j-1]+
                grid[i+1][j]+grid[i+1][j+1]);
            }

        }
        return ans;
    }
};