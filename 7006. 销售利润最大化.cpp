/*给你一个整数 n 表示数轴上的房屋数量，编号从 0 到 n - 1 。

另给你一个二维整数数组 offers ，其中 offers[i] = [starti, endi, goldi] 表示第 i 个买家想要以 goldi 枚金币的价格购买从 starti 到 endi 的所有房屋。

作为一名销售，你需要有策略地选择并销售房屋使自己的收入最大化。

返回你可以赚取的金币的最大数目。

注意 同一所房屋不能卖给不同的买家，并且允许保留一些房屋不进行出售。

 */
 class Solution {
public:
    //动态规划
    //选择购买或者不购买，将end根据大小进行排序，当选择购买到达end的房子时，找到比当前start小的end进行购买
    //即当进行购买时:dp[i]=offers[i-1][2]+dp[left]
    //不购买时:dp[i]=dp[i-1];
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        sort(offers.begin(),offers.end(),[](const vector<int>&a,const vector<int>&b){
            return a[1]<b[1]||(a[1]==b[1]&&a[0]<b[0]);
        });
        int len=offers.size();
        vector<int>dp(len+1,0);
        for(int i=1;i<=len;++i){
            int left=0;
            int right=i-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(offers[mid][1]<offers[i-1][0]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            dp[i]=max(dp[i-1],dp[left]+offers[i-1][2]);
        }
        return dp[len];
    }
};