/*圆内一个 有效切割 ，符合以下二者之一：

该切割是两个端点在圆上的线段，且该线段经过圆心。
该切割是一端在圆心另一端在圆上的线段。




给你一个整数 n ，请你返回将圆切割成相等的 n 等分的 最少 切割次数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int numberOfCuts(int n) {
        if(n<2){
            return 0;
        }
        if(n%2==0){
           return n/2; 
        }
        return n;
    }
};