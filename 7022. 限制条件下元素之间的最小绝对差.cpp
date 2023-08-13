/*给你一个下标从 0 开始的整数数组 nums 和一个整数 x 。

请你找到数组中下标距离至少为 x 的两个元素的 差值绝对值 的 最小值 。

换言之，请你找到两个下标 i 和 j ，满足 abs(i - j) >= x 且 abs(nums[i] - nums[j]) 的值最小。

请你返回一个整数，表示下标距离至少为 x 的两个元素之间的差值绝对值的 最小值 。*/
class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int>cnt;//set中元素从小到大排序

        int len=nums.size();
        cnt.insert(INT_MIN/2);//防止溢出
        cnt.insert(INT_MAX);
        int ans=INT_MAX;
        for(int i=x;i<len;++i){
            cnt.insert(nums[i-x]);
            
            auto it=cnt.lower_bound(nums[i]);
            ans=min(ans,min(*it-nums[i],nums[i]-*--it));
            //将当前值与在cnt中的左右两个值互相比较相减，取较小值
        }
        return ans;
    }
};