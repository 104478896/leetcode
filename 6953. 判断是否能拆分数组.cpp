/*给你一个长度为 n 的数组 nums 和一个整数 m 。请你判断能否执行一系列操作，将数组拆分成 n 个 非空 数组。

在每一步操作中，你可以选择一个 长度至少为 2 的现有数组（之前步骤的结果） 并将其拆分成 2 个子数组，而得到的 每个 子数组，至少 需要满足以下条件之一：

子数组的长度为 1 ，或者
子数组元素之和 大于或等于  m 。
如果你可以将给定数组拆分成 n 个满足要求的数组，返回 true ；否则，返回 false 。

注意：子数组是数组中的一个连续非空元素序列。*/
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int len=nums.size();
        if(len<=2){
            return true;
        }
        //在划分成那个子数组的过程中，要想满足条件，需要满足至少含有一组两个相邻数字和大于等于m
        for(int i=0;i<len-1;++i){
            if(nums[i]+nums[i+1]>=m){
                return true;
            }

        }
        return false;
    }
};