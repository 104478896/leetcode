/*给定一个长度为 n 的环形整数数组 nums ，返回 nums 的非空 子数组 的最大可能和 。

环形数组 意味着数组的末端将会与开头相连呈环状。形式上， nums[i] 的下一个元素是 nums[(i + 1) % n] ， nums[i] 的前一个元素是 nums[(i - 1 + n) % n] 。

子数组 最多只能包含固定缓冲区 nums 中的每个元素一次。形式上，对于子数组 nums[i], nums[i + 1], ..., nums[j] ，不存在 i <= k1, k2 <= j 其中 k1 % n == k2 % n 。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-sum-circular-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int len=nums.size();
        int ans=nums[0];
        int sum=nums[0];
        vector<int>leftMax(len);
        leftMax[0]=nums[0];//记录从零开始的位置的叠加数组值的最大值
        int leftSum=nums[0];
        for(int i=1;i<len;++i){
            sum=max(nums[i],sum+nums[i]);
            leftSum+=nums[i];
            leftMax[i]=max(leftMax[i-1],leftSum);
            ans=max(ans,sum);
        }
        int rightSum=0;

        for(int i=len-1;i>0;--i){
            rightSum+=nums[i];
            ans=max(ans,leftMax[i-1]+rightSum);
        }
        return ans;
    }
};