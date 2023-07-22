/*整数数组 nums 按升序排列，数组中的值 互不相同 。

在传递给函数之前，nums 在预先未知的某个下标 k（0 <= k < nums.length）上进行了 旋转，使数组变为 [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]（下标 从 0 开始 计数）。例如， [0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中存在这个目标值 target ，则返回它的下标，否则返回 -1 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/search-in-rotated-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int len=nums.size();
        int left=0;
        int right=len-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]<target){
                //旋转数组，当mid位置大于左侧的数，代表左侧到中间位置是连续的
                //当mid位置的数小于左侧的数，代表left到mid之间发生了旋转
                //当mid位置的数既小于target又小于left的数，同时left位置的数小于等于target，
                //代表target在mid左侧
                //但是当left位置的数大于target时，代表target在mid右侧
                if(nums[mid]>nums[left]){
                    left=mid+1;
                }else if(nums[mid]<nums[left]&&nums[left]<=target){
                    right=mid-1;
                }else if(nums[mid]<nums[left]&&nums[left]>target){
                    left=mid+1;
                }else{
                    left=mid+1;
                }
            }else if(nums[mid]>target){
                if(nums[mid]>nums[right]&&nums[right]>=target){
                    left=mid+1;
                }else if(nums[mid]>nums[right]&&nums[right]<target){
                    right=mid-1;
                }else if(nums[mid]<nums[right]){
                    right=mid-1;
                }else{
                    right=mid-1;
                }
            }

        }
        return -1;
    }
};