/*给你一个下标从 0 开始的整数数组 nums ，请你找到 最左边 的中间位置 middleIndex （也就是所有可能中间位置下标最小的一个）。

中间位置 middleIndex 是满足 nums[0] + nums[1] + ... + nums[middleIndex-1] == nums[middleIndex+1] + nums[middleIndex+2] + ... + nums[nums.length-1] 的数组下标。

如果 middleIndex == 0 ，左边部分的和定义为 0 。类似的，如果 middleIndex == nums.length - 1 ，右边部分的和定义为 0 。

请你返回满足上述条件 最左边 的 middleIndex ，如果不存在这样的中间位置，请你返回 -1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-middle-index-in-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int sum=0;
        for(auto num:nums){
            sum+=num;
        }
        int len=nums.size();
        int leftSum=0;
        for(int i=0;i<len;++i){
            
            if(leftSum*2+nums[i]==sum){
                return i;
            }
            leftSum+=nums[i];
        }
        return -1;
    }
};