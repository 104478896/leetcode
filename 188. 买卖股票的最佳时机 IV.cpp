/*给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        k=min(k,len/2);
        vector<int>buy(k+1);
        vector<int>sell(k+1);
        buy[0]=-prices[0];
        sell[0]=0;
        for(int i=1;i<k;++i){
            buy[i]=INT_MIN/2;
        }
        for(int i=1;i<len;++i){
            buy[0]=max(buy[0],sell[0]-prices[i]);
            for(int j=1;j<=k;++j){
                buy[j]=max(buy[j],sell[j]-prices[i]);
                sell[j]=max(sell[j],buy[j-1]+prices[i]);
            }
        }
        return *max_element(sell.begin(),sell.end());
    }
};