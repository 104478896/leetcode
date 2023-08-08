/*给你一个整数数组 nums 。一个子数组 [numsl, numsl+1, ..., numsr-1, numsr] 的 和的绝对值 为 abs(numsl + numsl+1 + ... + numsr-1 + numsr) 。

请你找出 nums 中 和的绝对值 最大的任意子数组（可能为空），并返回该 最大值 。

abs(x) 定义如下：

如果 x 是负整数，那么 abs(x) = -x 。
如果 x 是非负整数，那么 abs(x) = x 。*/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int ans=nums[0];
        int maxSum=0;
        int minSum=0;
        for(auto num:nums){
            maxSum=max(num,num+maxSum);
            minSum=min(num,num+minSum);
            ans=max(ans,max(maxSum,abs(minSum)));
        }
        return ans;
    }
};