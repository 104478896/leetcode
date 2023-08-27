/*给你一个整数数组 nums ，你可以对它进行一些操作。

每次操作中，选择任意一个 nums[i] ，删除它并获得 nums[i] 的点数。之后，你必须删除 所有 等于 nums[i] - 1 和 nums[i] + 1 的元素。

开始你拥有 0 个点数。返回你能通过这些操作获得的最大点数。*/
class Solution {
public:
    int rob(vector<int>arr){
        int len=arr.size();
        int pre=0;
        int cur=0;
        for(int i=0;i<len;++i){
            int temp=cur;
            cur=max(cur,pre+arr[i]);
            pre=temp;
        }
        return max(pre,cur);
    }
    int deleteAndEarn(vector<int>& nums) {
        int len=nums.size();
        int ans=0;
        sort(nums.begin(),nums.end());
        vector<int>cnt={nums[0]};
        for(int i=1;i<len;++i){
            //相等的元素进行叠加
            if(nums[i]==nums[i-1]){
                cnt.back()+=nums[i];
            }else if(nums[i]==nums[i-1]+1){
                //当与前一个元素相差仅为一时，放在统计数组的后边
                cnt.push_back(nums[i]);
            }else {
                //当与前一个元素相差大于一时，代表时另一组数据，可以另外进行选择和删除
                ans+=rob(cnt);
                cnt={nums[i]};
            }
        }
        ans+=rob(cnt);
        return ans;
    }
};