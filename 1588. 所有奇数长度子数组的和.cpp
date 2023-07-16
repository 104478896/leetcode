/*给你一个正整数数组 arr ，请你计算所有可能的奇数长度子数组的和。

子数组 定义为原数组中的一个连续子序列。

请你返回 arr 中 所有奇数长度子数组的和 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sum-of-all-odd-length-subarrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // //暴力
        // int ans=0;
        // int len=arr.size();
        // for(int i=0;i<len;++i){
        //     for(int lengh=1;lengh+i<=len;lengh+=2){
        //         for(int j=i;j<i+lengh;++j){
        //             ans+=arr[j];
        //         }
        //     }
        // }
        // return ans;


        // //前缀和
        // int len=arr.size();
        // vector<int> pre(len+1,0);
        // for(int i=0;i<len;++i){
        //     pre[i+1]=pre[i]+arr[i];
        // }
        // int ans=0;
        // for(int i=0;i<len;++i){
        //     for(int lengh=1;i+lengh<=len;lengh+=2){
        //         int end=i+lengh-1;
        //         ans+=pre[end+1]-pre[i];
        //     }
        // }
        // return ans;


        //数学计算
        int ans=0;
        int len=arr.size();
        for(int i=0;i<len;++i){
            int leftCount=i;
            int rightCount=len-i-1;
            int leftOdd=(leftCount+1)/2;
            int rightOdd=(rightCount+1)/2;
            int leftEven=leftCount/2+1;
            int rightEven=rightCount/2+1;
            ans+=arr[i]*(leftOdd*rightOdd+leftEven*rightEven);
        }
        return ans;

    }
};