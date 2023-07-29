/*给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len=nums.size();
        vector<int>leftSub(len);
        leftSub[0]=1;

        vector<int>rightSub(len);
        rightSub[len-1]=1;
        for(int i=1;i<len;++i){
            leftSub[i]=leftSub[i-1]*nums[i-1];
        }
        for(int i=len-2;i>=0;--i){
            rightSub[i]=rightSub[i+1]*nums[i+1];
        }
        vector<int>ans;
        for(int i=0;i<len;++i){
            // cout<<leftSub[i]<<endl;
            // cout<<rightSub[i]<<endl;
            ans.push_back(leftSub[i]*rightSub[i]);
        }
        return ans;
    }
};