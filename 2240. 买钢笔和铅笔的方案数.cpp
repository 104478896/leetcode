/*给你一个整数 total ，表示你拥有的总钱数。同时给你两个整数 cost1 和 cost2 ，分别表示一支钢笔和一支铅笔的价格。你可以花费你部分或者全部的钱，去买任意数目的两种笔。

请你返回购买钢笔和铅笔的 不同方案数目 。*/
class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if(cost1<cost2){
            return waysToBuyPensPencils(total,cost2,cost1);
        }
        long long ans=0;
        long long cnt=0;//购买的较贵的文具的数量，减少枚举次数
        while(cnt*cost1<=total){
            ans+=(total-cnt*cost1)/cost2+1;
            cnt++;
        }
        return ans;
    }
};