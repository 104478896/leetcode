/*给你一个 n x n 整数矩阵 grid ，请你返回 非零偏移下降路径 数字和的最小值。

非零偏移下降路径 定义为：从 grid 数组中的每一行选择一个数字，且按顺序选出来的数字中，相邻数字不在原数组的同一列。*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int len=grid.size();
        vector<vector<int>>dp(len,vector<int>(len,INT_MAX));
        for(int i=0;i<len;++i){
            dp[0][i]=grid[0][i];
        }
        for(int i=1;i<len;++i){//行
            for(int j=0;j<len;++j){
                for(int k=0;k<len;++k){
                    if(j==k){
                        continue;
                    }
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+grid[i][j]);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<len;++i){
            ans=min(ans,dp[len-1][i]);
        }
        return ans;
    }
};