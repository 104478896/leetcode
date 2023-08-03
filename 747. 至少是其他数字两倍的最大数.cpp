/*给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。

请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。如果是，则返回 最大元素的下标 ，否则返回 -1 。*/
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum=*max_element(nums.begin(),nums.end());
        int len=nums.size();
        int index=-1;
        for(int i=0;i<len;++i){
            if(nums[i]!=maxNum&&nums[i]*2>maxNum){
                return -1;
            }
            if(nums[i]==maxNum){
                index=i;
            }
            
        }
        return index;

    }
};