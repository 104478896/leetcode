/*给定一个数组 points ，其中 points[i] = [xi, yi] 表示 X-Y 平面上的一个点，并且是一个整数 k ，返回离原点 (0,0) 最近的 k 个点。

这里，平面上两点之间的距离是 欧几里德距离（ √(x1 - x2)2 + (y1 - y2)2 ）。

你可以按 任何顺序 返回答案。除了点坐标的顺序之外，答案 确保 是 唯一 的。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/k-closest-points-to-origin
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b){//二维数组排序函数
        return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(),points.end(),cmp);//对数组根据距离从小到大排序
        vector<vector<int>>ans;
        for(int i=0;i<k;++i){//前k个为结果
            ans.push_back(points[i]);
            
        }
        return ans;
    }
};