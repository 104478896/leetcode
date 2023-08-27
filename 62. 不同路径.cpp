/*一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>cnt(m,vector<int>(n));
        for(int i=0;i<m;++i){
            cnt[i][0]=1;
        }
        for(int i=0;i<n;++i){
            cnt[0][i]=1;
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                cnt[i][j]=cnt[i-1][j]+cnt[i][j-1];
            }
        }
        return cnt[m-1][n-1];

        //  //滚动数组
        // vector<int>dp(n);
        // dp[0]=1;
        // for(int i=0;i<m;++i){
        //     for(int j=1;j<n;++j){
        //         dp[j]+=dp[j-1];
        //     }
        // }
        // return dp[n-1];
    }
};