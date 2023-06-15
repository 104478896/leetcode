/*给你一个 不包含 任何零的整数数组 nums ，找出自身与对应的负数都在数组中存在的最大正整数 k 。

返回正整数 k ，如果不存在这样的整数，返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-positive-integer-that-exists-with-its-negative
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/


class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int left=0;
        int right=nums.size()-1;
        // int ans=-1;
        while(left<right){
            if(-1*nums[left]!=nums[right]&&(-1)*nums[left]>nums[right]){
                left++;
            }else if(-1*nums[left]!=nums[right]&&(-1)*nums[left]<nums[right]){
                right--;
            }else{
                return nums[right];
            }
        }
        return -1;
    }
};