/*给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int maxSum=0;
        for(auto num:nums){
            maxSum=max(num,maxSum+num);
            ans=max(maxSum,ans);
        }
        return ans;
    }
};