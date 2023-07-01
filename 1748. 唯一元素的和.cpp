/*给你一个整数数组 nums 。数组中唯一元素是那些只出现 恰好一次 的元素。

请你返回 nums 中唯一元素的 和 。*/
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int>count;
        for(auto num:nums){
            count[num]++;
            // cout<<num<<endl;
        }
        int ans=0;
        for(auto [key,val]:count){
            // cout<<key<<endl;
            if(val==1){
                
                ans+=key;
            }
        }
        return ans;
    }
};