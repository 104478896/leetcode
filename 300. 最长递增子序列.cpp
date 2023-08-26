/*给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int index=1;
        int len=nums.size();
        if(len==0){
            return 0;
        }
        vector<int>dp(len+1,0);
        dp[index]=nums[0];
        for(int i=1;i<len;++i){
            if(dp[index]<nums[i]){
                dp[++index]=nums[i];
            }else{
                int left=1;
                int right=index;
                int pos=0;
                while(left<=right){
                    int mid=left+(right-left)/2;
                    if(dp[mid]<nums[i]){
                        pos=mid;
                        left=mid+1;
                    }else{
                        right=mid-1;
                    }
                }
                dp[pos+1]=nums[i];
            }
        }
        return index;
    }
};