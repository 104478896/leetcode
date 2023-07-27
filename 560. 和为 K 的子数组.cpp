/*给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>cnt;
        cnt[0]=1;
        int len=nums.size();
        int ans=0;
        int pre=0;
        for(int i=0;i<len;++i){
            pre+=nums[i];
            if(cnt.count(pre-k)){
                ans+=cnt[pre-k];
            }
            cnt[pre]++;
        }
        return ans;
    }
};