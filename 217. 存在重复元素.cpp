/*给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>cnt;
        for(auto num:nums){
            if(cnt.count(num)){
                return true;
            }
            cnt.insert(num);
        }
        return false;
    }
};