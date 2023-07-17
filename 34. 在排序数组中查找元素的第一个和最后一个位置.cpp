/*给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int lower_bound(vector<int>&nums,int target){
        int left=0;
        int right=nums.size()-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]<target){
                left=mid+1;
            }else if(nums[mid]>=target){
                right=mid-1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=lower_bound(nums,target);
        if(start==nums.size()||nums[start]!=target){
            return {-1,-1};
        }
        int end=lower_bound(nums,target+1)-1;
        return {start,end};
    }
};