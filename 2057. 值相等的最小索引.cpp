/*给你一个下标从 0 开始的整数数组 nums ，返回 nums 中满足 i mod 10 == nums[i] 的最小下标 i ；如果不存在这样的下标，返回 -1 。

x mod y 表示 x 除以 y 的 余数 。*/
class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int len=nums.size();
        for(int i=0;i<len;++i){
            if(i%10==nums[i]){
                return i;
            }
        }
        return -1;
    }
};