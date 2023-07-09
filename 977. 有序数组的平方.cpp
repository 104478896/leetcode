/*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。*/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mid=-1;
        int len=nums.size();
        for(int i=0;i<len;++i){
            if(nums[i]<0){
                mid=i;
            }else{
                break;
            }
        }
        int left=mid;
        int right=mid+1;
        vector<int>ans;
        while(left>=0||right<len){
            if(left<0){
                ans.push_back(nums[right]*nums[right]);
                right++;
            }else if(right==len){
                ans.push_back(nums[left]*nums[left]);
                left--;
            }else if(nums[left]*nums[left]<nums[right]*nums[right]){
                ans.push_back(nums[left]*nums[left]);
                left--;
            }else{
                ans.push_back(nums[right]*nums[right]);
                right++;
            }
        }
        return ans;
    }

};