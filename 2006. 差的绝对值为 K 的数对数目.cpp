/*给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且 |nums[i] - nums[j]| == k 。

|x| 的值定义为：

如果 x >= 0 ，那么值为 x 。
如果 x < 0 ，那么值为 -x 。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        // //暴力
        // int ans=0;
        // int len=nums.size();
        // for(int i=0;i<len-1;++i){
        //     for(int j=i+1;j<len;++j){
        //         if(abs(nums[i]-nums[j])==k){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;
        //哈希表
        int ans=0;
        map<int,int>cnt;
        for(auto num:nums){
            ans+=cnt.count(num+k)?cnt[num+k]:0;
            ans+=cnt.count(num-k)?cnt[num-k]:0;
            cnt[num]++;
        }
        return ans;
    }
};