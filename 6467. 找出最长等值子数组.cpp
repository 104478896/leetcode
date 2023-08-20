/*给你一个下标从 0 开始的整数数组 nums 和一个整数 k 。

如果子数组中所有元素都相等，则认为子数组是一个 等值子数组 。注意，空数组是 等值子数组 。

从 nums 中删除最多 k 个元素后，返回可能的最长等值子数组的长度。

子数组 是数组中一个连续且可能为空的元素序列。*/
class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        int len=nums.size();
        vector<vector<int>>cnt(len+1);
        for(int i=0;i<len;++i){
            //记录当前位置需要删除的其余数字个数
            cnt[nums[i]].push_back(i-cnt[nums[i]].size());
        }
        int ans=0;
        for(auto temp:cnt){
            int left=0;
            for(int right=0;right<temp.size();++right){
                while(temp[right]-temp[left]>k){
                    left++;
                }
                ans=max(ans,right-left+1);
            }
        }
        return ans;
    }
};