/*给你一个整数数组，返回它的某个 非空 子数组（连续元素）在执行一次可选的删除操作后，所能得到的最大元素总和。换句话说，你可以从原数组中选出一个子数组，并可以决定要不要从中删除一个元素（只能删一次哦），（删除后）子数组中至少应当有一个元素，然后该子数组（剩下）的元素总和是所有子数组之中最大的。

注意，删除一个元素后，子数组 不能为空。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp0=arr[0];//不删除第一个元素
        int dp1=0;//删除第一个元素
        int ans=dp0;
        int len=arr.size();
        for(int i=1;i<len;++i){
            if(dp0<dp1+arr[i]){//将删除元素的大小和不删除元素的大小比对，
            //如果删除后比删除前大，之前不删元素的结果即为当前的最大值
            //否则当前最大值为加上当前的值
                dp1=dp1+arr[i];
            }else{
                dp1=dp0;
            }
            if(dp0>0){
                dp0=dp0+arr[i];
            }else{
                dp0=arr[i];
            }
            ans=max(ans,max(dp0,dp1));
        }
        return ans;
    }
};