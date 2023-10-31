/*设计一个算法收集某些股票的每日报价，并返回该股票当日价格的 跨度 。

当日股票价格的 跨度 被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。

例如，如果未来 7 天股票的价格是 [100,80,60,70,60,75,85]，那么股票跨度将是 [1,1,1,2,1,4,6] 。

实现 StockSpanner 类：

StockSpanner() 初始化类对象。
int next(int price) 给出今天的股价 price ，返回该股票当日价格的 跨度 。*/
class StockSpanner {
private:
    stack<pair<int,int>>stk;
    int idx;
public:
    StockSpanner() {
        this->stk.emplace(-1,INT_MAX);
        this->idx=-1;
    }
    
    int next(int price) {
        idx++;
        while(price>=stk.top().second){
            stk.pop();
        }
        int res=idx-stk.top().first;
        stk.push({idx,price});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */