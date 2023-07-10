/*给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int len=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[0]+nums[1]+nums[2];
        for(int i=0;i<len-2;++i){
            if(i>0&&nums[i]==nums[i-1]){
                continue;
            }
            int left=i+1;
            int right=len-1;
            while(left<right){
                int temp=nums[left]+nums[right]+nums[i];
                if(abs(target-temp)<abs(target-ans)){
                    ans=temp;
                }
                if(temp==target){
                    return target;
                }else if(temp<target){
                    left++;

                }else{
                    right--;
                }
                
            }
        }
        return ans;
    }
};