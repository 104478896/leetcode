/*给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/two-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // //暴力
        // vector<int>ans;
        // int len=nums.size();
        // for(int i=0;i<len;++i){
        //     for(int j=i+1;j<len;++j){
        //         if(nums[i]+nums[j]==target){
        //             ans.push_back(i);
        //             ans.push_back(j);
        //             return ans;
        //         }
        //     }
        // }
        // return ans;

        //哈希
        vector<int>ans;
        map<int,int>sub;
        int len=nums.size();
        for(int i=0;i<len;++i){
            if(sub.find(target-nums[i])!=sub.end()){//如果哈希表中有对应值，将下标返回
                return {sub[target-nums[i]],i};
            }
            sub[nums[i]]=i;//找不到将该值与对应下标作为键值对存入哈希表
        }
        return {};

    }
};