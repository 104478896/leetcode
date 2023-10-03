/*给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //动态规划
        // int len=prices.size();
        // int dp0=0;//手中没有股票的最大利润
        // int dp1=-prices[0];//交易完手中的股票的最大利润
        // for(int i=1;i<len;++i){
        //     int newDp0=max(dp0,dp1+prices[i]);
        //     int newDp1=max(dp1,dp0-prices[i]);
        //     dp0=newDp0;
        //     dp1=newDp1;
        // }
        // return dp0;

        //贪心
        int ans=0;
        int len=prices.size();
        for(int i=1;i<len;++i){
            int temp=prices[i]-prices[i-1];
            if(temp>0){
                ans+=prices[i]-prices[i-1];
            }
        }
        return ans;
    }
};