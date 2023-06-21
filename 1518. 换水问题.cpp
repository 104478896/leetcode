/*超市正在促销，你可以用 numExchange 个空水瓶从超市兑换一瓶水。最开始，你一共购入了 numBottles 瓶水。

如果喝掉了水瓶中的水，那么水瓶就会变成空的。

给你两个整数 numBottles 和 numExchange ，返回你 最多 可以喝到多少瓶水。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/water-bottles
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            ans+=numBottles/numExchange;//每次加上手中的瓶子数
            //每次可兑换的数量为手中瓶子可以交换到的加上之前剩下的
            numBottles=numBottles/numExchange+numBottles%numExchange;
        }
        return ans;

    }
};