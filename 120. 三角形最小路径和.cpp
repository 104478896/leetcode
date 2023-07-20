/*给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/triangle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        ////暴力，添加一个动态转移数组，保存之前的最短路径的和
        ////时间复杂度: O(n^2)
        ////空间复杂度: O(n^2)
        // int len=triangle.size();
        // vector<vector<int>> dp(len,vector<int>(len));
        // dp[0][0]=triangle[0][0];
        // for(int i=1;i<len;++i){
        //     dp[i][0]=dp[i-1][0]+triangle[i][0];
        //     for(int j=1;j<i;++j){
        //         dp[i][j]=min(dp[i-1][j],dp[i-1][j-1])+triangle[i][j];
        //     }
        //     dp[i][i]=dp[i-1][i-1]+triangle[i][i];
        // }
        // return *min_element(dp[len-1].begin(),dp[len-1].end());


        //动态规划+空间优化
        //截至当前行的最短路径仅和上一行的数组值有关，
        //将动态转移中的二维数组缩减为一维数组，仅保存上一行内容
        //更改动态数组中的值时，从右向左更改，避免添加的数为已更改数
        
        int len=triangle.size();
        vector<int>dp(len);
        dp[0]=triangle[0][0];
        for(int i=1;i<len;++i){
            dp[i]=dp[i-1]+triangle[i][i];
            for(int j=i-1;j>0;--j){
                dp[j]=min(dp[j-1],dp[j])+triangle[i][j];
            }
            dp[0]=dp[0]+triangle[i][0];
        }

        return *min_element(dp.begin(),dp.end());


    }
};