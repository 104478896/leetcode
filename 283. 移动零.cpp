/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left=0;
        int right=0;
        int len=nums.size();
        while(right<len){
            if(nums[right]!=0){
                swap(nums[left],nums[right]);
                left++;
            }
            right++;
        }
        
    }
};