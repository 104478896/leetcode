/*给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee 代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。*/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int len=prices.size();
        int sell=0;
        int buy=-prices[0];
        for(int i=1;i<len;++i){
            int newBuy=max(buy,sell-prices[i]);
            int newSell=max(sell,buy+prices[i]-fee);
            buy=newBuy;
            sell=newSell;
        }
        return sell;

    }
};