/*给定一个数组 coordinates ，其中 coordinates[i] = [x, y] ， [x, y] 表示横坐标为 x、纵坐标为 y 的点。请你来判断，这些点是否在该坐标系中属于同一条直线上。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-it-is-a-straight-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int len=coordinates.size();
        for(int i=1;i<len-1;++i){
            //两点式求直线，(y-y1)/(x-x1)=(y-y2)/(x-x2) <==> (x-x1)*(y-y2)=(y-y1)*(x-x2)
            //(x1,y1)==>第一个点      (x2,y2)==>最后一个点
            if((coordinates[i][0]-coordinates[0][0])*(coordinates[i][1]-coordinates[len-1][1])
            !=
            (coordinates[i][1]-coordinates[0][1])*(coordinates[i][0]-coordinates[len-1][0])){
                return false;
            }
        }
        return true;
    }
};