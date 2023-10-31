/*矩形蛋糕的高度为 h 且宽度为 w，给你两个整数数组 horizontalCuts 和 verticalCuts，其中：

 horizontalCuts[i] 是从矩形蛋糕顶部到第  i 个水平切口的距离
verticalCuts[j] 是从矩形蛋糕的左侧到第 j 个竖直切口的距离
请你按数组 horizontalCuts 和 verticalCuts 中提供的水平和竖直位置切割后，请你找出 面积最大 的那份蛋糕，并返回其 面积 。由于答案可能是一个很大的数字，因此需要将结果 对 109 + 7 取余 后返回。*/
class Solution {
public:
    int get_maxNum(int size,vector<int>&arr){
        sort(arr.begin(),arr.end());
        int res=max(arr[0],size-arr.back());
        for(int i=1;i<arr.size();++i){
            res=max(res,arr[i]-arr[i-1]);
        }
        return res;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod=1e9+7;
        int max_h=get_maxNum(h,horizontalCuts);
        int max_w=get_maxNum(w,verticalCuts);
        return (long long)max_h*max_w%mod;
    }
};