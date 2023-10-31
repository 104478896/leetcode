/*给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int dp0=-prices[0];//手上持有股票的最大收益
        int dp1=0;//手上不持有股票，并且处于冷冻期中的累计最大收益
        int dp2=0;//手上不持有股票，并且不再冷冻期中的累计最大收益
        for(int i=1;i<len;++i){
            int newDp0=max(dp0,dp2-prices[i]);
            int newDp1=dp0+prices[i];
            int newDp2=max(dp1,dp2);
            dp0=newDp0;
            dp1=newDp1;
            dp2=newDp2;
        }
        return max(dp1,dp2);
    }
};