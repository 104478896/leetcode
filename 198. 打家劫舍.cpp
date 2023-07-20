/*你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/house-robber
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int rob(vector<int>& nums) {
        
        int len=nums.size();
        
        int odd=0;
        int even=0;
        //odd表示dp[k-2] 
        //even表示dp[k-1]
        //dp[k]=max(dp[k-1],dp[k-2]+num) ==>  dp[k+1]=max(dp[k],dp[k-1]+num)
        for(int i=0;i<len;++i){
            int temp=even;
            even=max(nums[i]+odd,even);
            odd=temp;
            
        }
        return even;
    }
};