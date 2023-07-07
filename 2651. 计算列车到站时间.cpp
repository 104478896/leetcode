/*给你一个正整数 arrivalTime 表示列车正点到站的时间（单位：小时），另给你一个正整数 delayedTime 表示列车延误的小时数。

返回列车实际到站的时间。

注意，该问题中的时间采用 24 小时制。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/calculate-delayed-arrival-time
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int findDelayedArrivalTime(int arrivalTime, int delayedTime) {
        int ans=arrivalTime+delayedTime;
        return ans%24;
    }
};