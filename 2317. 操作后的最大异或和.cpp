/*给你一个下标从 0 开始的整数数组 nums 。一次操作中，选择 任意 非负整数 x 和一个下标 i ，更新 nums[i] 为 nums[i] AND (nums[i] XOR x) 。

注意，AND 是逐位与运算，XOR 是逐位异或运算。

请你执行 任意次 更新操作，并返回 nums 中所有元素 最大 逐位异或和。*/
class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        // nums[i] AND (nums[i] XOR x)
        //意味着可以将nums[i]更换成任意数
        // nums[i] AND (nums[i] XOR x) ==>  nums[i] AND x
        //在与运算中0不可以化为1，但是1可以化为0
        
        //结果求最大异或和
        //逐位考虑，从大到小，保证结果最大，只要该比特位存在1 就将1提取出来 可以保证结果的最大
        //而提取每一个比特位的1  保证只要数组中的任意数在该比特位存在1 就可以提取
        
        //或运算中，只要存在1，就为1
        //没有1，则只能为0
        int ans=nums[0];
        for(auto num:nums){
            ans|=num;
        }
        return ans;
    }
};