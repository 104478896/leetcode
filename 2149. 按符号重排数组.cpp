/*给你一个下标从 0 开始的整数数组 nums ，数组长度为 偶数 ，由数目相等的正整数和负整数组成。

你需要 重排 nums 中的元素，使修改后的数组满足下述条件：

任意 连续 的两个整数 符号相反
对于符号相同的所有整数，保留 它们在 nums 中的 顺序 。
重排后数组以正整数开头。
重排元素满足上述条件后，返回修改后的数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/rearrange-array-elements-by-sign
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int len=nums.size();
        vector<int> ans(len);

        int pos=0;
        int neg=1;
        for(auto num:nums){
            if(num>0){
                ans[pos]=num;
                pos+=2;
            }else{
                ans[neg]=num;
                neg+=2;
            }
        }
        return ans;
    }
};