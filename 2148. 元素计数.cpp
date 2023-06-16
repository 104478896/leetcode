/*给你一个整数数组 nums ，统计并返回在 nums 中同时至少具有一个严格较小元素和一个严格较大元素的元素数目。
 */
 class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxNum=*max_element(nums.begin(),nums.end());//获取最大值
        int minNum=*min_element(nums.begin(),nums.end());//获取最小值
        int ans=0;
        for(auto num:nums){
            //获取数组值，小于最大值同时大于最大值的则将结果加一
            if(num<maxNum&&num>minNum){
                ans++;
            }
        }
        return ans;

    }
};