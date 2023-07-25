/*如果数组是单调递增或单调递减的，那么它是 单调 的。

如果对于所有 i <= j，nums[i] <= nums[j]，那么数组 nums 是单调递增的。 如果对于所有 i <= j，nums[i]> = nums[j]，那么数组 nums 是单调递减的。

当给定的数组 nums 是单调数组时返回 true，否则返回 false。*/
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int len=nums.size();
        if(len<2){
            return true;
        }

        int flag;
        int index=0;
        while(index<len){
            if(nums[index]!=nums[0]){
                break;
            }
            index++;
        }
        if(index==len){
            return true;
        }
        if(nums[index]>nums[0]){
            flag=1;
        }else{
            flag=-1;
        }
        for(int i=1;i<len;++i){
            if(nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>nums[i-1]&&flag==1){
                continue;
            }else if(nums[i]<nums[i-1]&&flag==-1){
                continue;
            }else{
                return false;
            }
            
        }
        return true;
    }
};