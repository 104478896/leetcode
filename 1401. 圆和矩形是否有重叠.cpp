/*给你一个以 (radius, xCenter, yCenter) 表示的圆和一个与坐标轴平行的矩形 (x1, y1, x2, y2) ，其中 (x1, y1) 是矩形左下角的坐标，而 (x2, y2) 是右上角的坐标。

如果圆和矩形有重叠的部分，请你返回 true ，否则返回 false 。

换句话说，请你检测是否 存在 点 (xi, yi) ，它既在圆上也在矩形上（两者都包括点落在边界上的情况）。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/circle-and-rectangle-overlapping
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long int sum=0;
        if(x1>xCenter||x2<xCenter){
            sum+=min((x1-xCenter)*(x1-xCenter),(x2-xCenter)*(x2-xCenter));
        }
        if(y1>yCenter||y2<yCenter){
            sum+=min((y1-yCenter)*(y1-yCenter),(y2-yCenter)*(y2-yCenter));
        }
        return sum<=radius*radius;
    }
};