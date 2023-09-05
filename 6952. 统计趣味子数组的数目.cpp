/*给你一个下标从 0 开始的整数数组 nums ，以及整数 modulo 和整数 k 。

请你找出并统计数组中 趣味子数组 的数目。

如果 子数组 nums[l..r] 满足下述条件，则称其为 趣味子数组 ：

在范围 [l, r] 内，设 cnt 为满足 nums[i] % modulo == k 的索引 i 的数量。并且 cnt % modulo == k 。
以整数形式表示并返回趣味子数组的数目。

注意：子数组是数组中的一个连续非空的元素序列。*/
class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans=0;
        int len=nums.size();
        map<int,int>cnt;
        cnt[0]=1;
        int dp=0;
        for(int i=0;i<len;++i){
            dp+=(nums[i]%modulo==k);
            ans+=cnt[(dp-k+modulo)%modulo];
            cnt[dp%modulo]++;
        }
        return ans;
    }
};