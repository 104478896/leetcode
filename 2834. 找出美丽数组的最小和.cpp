/*给你两个正整数：n 和 target 。

如果数组 nums 满足下述条件，则称其为 美丽数组 。

nums.length == n.
nums 由两两互不相同的正整数组成。
在范围 [0, n-1] 内，不存在 两个 不同 下标 i 和 j ，使得 nums[i] + nums[j] == target 。
返回符合条件的美丽数组所可能具备的 最小 和。*/
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        long long ans=0;
        long long m=min(n,target/2);
        ans=(m+1)*m/2+(target+target+n-m-1)*(n-m)/2;
        return ans;
    }
};