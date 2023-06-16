/*给你一个正整数数组 nums 。

元素和 是 nums 中的所有元素相加求和。
数字和 是 nums 中每一个元素的每一数位（重复数位需多次求和）相加求和。
返回 元素和 与 数字和 的绝对差。

注意：两个整数 x 和 y 的绝对差定义为 |x - y| 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/difference-between-element-sum-and-digit-sum-of-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int eleSum=0;
        int numSum=0;
        int len=nums.size();
        for(int i=0;i<len;++i){
            eleSum+=nums[i];
            int temp=nums[i];
            while(temp){
                numSum+=temp%10;
                temp=temp/10;
            }

        }
        int ans=abs(eleSum-numSum);
        return ans;
    }
};