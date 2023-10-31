/*给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。

你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;
        map<int,int>cnt;
        for(auto num:nums){
            cnt[num]++;
        }
        for(auto [key,val]:cnt){
            if(cnt[key]==1){
                ans.push_back(key);
            }
        }
        return ans;
    }
};