/*给你一个整数数组 nums 。

如果一组数字 (i,j) 满足 nums[i] == nums[j] 且 i < j ，就可以认为这是一组 好数对 。

返回好数对的数目。*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // //暴力
        // int ans=0;
        // int len=nums.size();
        // for(int i=0;i<len;++i){
        //     for(int j=i+1;j<len;++j){
        //         if(nums[i]==nums[j]){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
        //哈希统计，计数
        map<int,int>cnt;
        for(auto num:nums){
            cnt[num]++;
        }
        int ans=0;
        for(auto [key,val]:cnt){
            ans+=(val*(val-1))/2;
        }
        return ans;
    }
};