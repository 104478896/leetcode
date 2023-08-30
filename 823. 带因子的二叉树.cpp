/*给出一个含有不重复整数元素的数组 arr ，每个整数 arr[i] 均大于 1。

用这些整数来构建二叉树，每个整数可以使用任意次数。其中：每个非叶结点的值应等于它的两个子结点的值的乘积。

满足条件的二叉树一共有多少个？答案可能很大，返回 对 109 + 7 取余 的结果。*/
class Solution {
public:
    const int MOD=1e9+7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int len=arr.size();
        vector<long long>dp(len);
        long long ans=0;
        for(int i=0;i<len;++i){
            dp[i]=1;
            int right=i-1;
            for(int left=0;left<=right;++left){
                while(right>=left&&(long long)arr[left]*arr[right]>arr[i]){
                    right--;
                }
                if(right>=left&&(long long)arr[left]*arr[right]==arr[i]){
                    if(right!=left){
                        dp[i]=(dp[i]+2*dp[left]*dp[right])%MOD;
                    }else{
                        dp[i]=(dp[i]+dp[left]*dp[right])%MOD;
                    }
                }
            }
            ans=(ans+dp[i])%MOD;
        }
        return ans;
    }
};