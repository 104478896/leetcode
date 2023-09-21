/*你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

 */
 class Solution {
public:
    int robSub(vector<int>&nums,int start,int end){
        int cur=0;
        int pre=0;
        for(int i=start;i<end;++i){
            int temp=cur;
            cur=max(cur,pre+nums[i]);
            pre=temp;
        }
        return max(cur,pre);
    }
    int rob(vector<int>& nums) {
        int len=nums.size();
        return max(robSub(nums,1,len),nums[0]+robSub(nums,2,len-1));
    }
};