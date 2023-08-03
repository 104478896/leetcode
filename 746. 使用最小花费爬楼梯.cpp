/*给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len=cost.size();
        int pre=0;
        int cur=0;
        for(int i=2;i<=len;++i){
            int temp=min(pre+cost[i-2],cur+cost[i-1]);
            pre=cur;
            cur=temp;
        }
        return cur;
    }
};