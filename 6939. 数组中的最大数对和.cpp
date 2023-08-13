/*给你一个下标从 0 开始的整数数组 nums 。请你从 nums 中找出和 最大 的一对数，且这两个数数位上最大的数字相等。

返回最大和，如果不存在满足题意的数字对，返回 -1 。*/
class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<char,int>cnt;
        int len=nums.size();
        int ans=-1;
        for(int i=0;i<len;++i){
            string temp=to_string(nums[i]);
            sort(temp.begin(),temp.end());
            if(cnt.count(temp.back())){
                ans=max(ans,cnt[temp.back()]+nums[i]);
                cnt[temp.back()]=max(nums[i],cnt[temp.back()]);
            }else{
                cnt[temp.back()]=nums[i];
            }
        }
        return ans;
    }
};