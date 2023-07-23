/*给你一个下标从 0 开始、由正整数组成的数组 nums 。

你可以在数组上执行下述操作 任意 次：

选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1] 的整数 i 。将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，并从数组中删除元素 nums[i] 。
返回你可以从最终数组中获得的 最大 元素的值。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-element-in-an-array-after-merge-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        long long ans=0;
        int len=nums.size();
        //从右向左，当数组中的数大于和ans时，代表之后的数可以舍弃
        //将ans赋值为该数组值
        //每当数组值小于等于ans时，代表符合条件，可以累加
        for(int i=len-1;i>=0;--i){
            if(nums[i]>ans){
                ans=nums[i];
            }else{
                ans+=nums[i];
            }
        }
        return ans;
    }
};