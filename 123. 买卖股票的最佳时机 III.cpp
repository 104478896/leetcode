/*给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len=prices.size();
        int buy1=-prices[0];//只进行一次买操作
        int sell1=0;//进行一次买卖操作
        int buy2=-prices[0];//进行一次卖两次买操作
        int sell2=0;//进行两轮买卖操作
        for(int i=1;i<len;++i){
            buy1=max(buy1,-prices[i]);
            sell1=max(sell1,buy1+prices[i]);
            buy2=max(buy2,sell1-prices[i]);
            sell2=max(sell2,buy2+prices[i]);
        }
        return sell2;
    }
};