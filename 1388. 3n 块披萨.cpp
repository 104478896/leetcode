/*给你一个披萨，它由 3n 块不同大小的部分组成，现在你和你的朋友们需要按照如下规则来分披萨：

你挑选 任意 一块披萨。
Alice 将会挑选你所选择的披萨逆时针方向的下一块披萨。
Bob 将会挑选你所选择的披萨顺时针方向的下一块披萨。
重复上述过程直到没有披萨剩下。
每一块披萨的大小按顺时针方向由循环数组 slices 表示。

请你返回你可以获得的披萨大小总和的最大值。*/

class Solution {
public:
    int select(vector<int>&nums){
        int len=nums.size();//披萨总数
        int have=(len+1)/3;//自己选择的总披萨数
        vector<vector<int>>dp(len,vector<int>(have+1,INT_MIN));
        //当总数小于2或者自己选择的数为0时
        dp[0][0]=0;//初始化0，拥有0块
        dp[0][1]=nums[0];//选择第0块
        dp[1][0]=0;//初始化0,拥有0块
        dp[1][1]=max(nums[0],nums[1]);//第0块和第1块选择一块较大的
        for(int i=2;i<len;++i){
            dp[i][0]=0;//
            for(int j=1;j<=have;++j){
                //在第i块披萨处，选择和不选择进行动态规划
                //选择时:选择后保证自身拥有j块，则找到之前已有j-1块，同时不可以选择前一块，即dp[i-2][j-1]
                //      选择时为 :dp[i-2][j-1]+nums[i]
                //不选择时:不选择的前提是已经选择了j块，同时前一块可以选择
                //      不选择时为:dp[i-1][j]
                dp[i][j]=max(dp[i-2][j-1]+nums[i],dp[i-1][j]);
            }
        }
        return dp[len-1][have];
    }
    int maxSizeSlices(vector<int>& slices) {
        vector<int>arr1(slices.begin()+1,slices.end());//不选择第一个
        vector<int>arr2(slices.begin(),slices.end()-1);//不选择最后一个
        int ans1=select(arr1);
        int ans2=select(arr2);
        return max(ans1,ans2);
    }
};

/*我们首先考虑该序列不是环状时的解决方法，即给定的是长度为 3n3n3n 的普通序列。我们可以用 dp[i][j]\textit{dp}[i][j]dp[i][j] 表示在前 iii 个数中选择了 jjj 个不相邻的数的最大和：

当 i≥2且 j>0时，dp[i][j] 可以从两个位置转移而来：

如果我们选择了第 i 个数，那么第 i−1 个数不能被选择，相当于需要在前 i−2 个数中选择 j−1 个，
即 dp[i][j]=dp[i−2][j−1]+slices[i]。

如果我们没有选择第 i 个数，那么需要在前 i−1 个数中选择 j个，
即 dp[i][j]=dp[i−1][j]。

取两者的最大值即为状态转移方程：

dp[i][j]=max⁡(dp[i−2][j−1]+slices[i],dp[i−1][j]) 
当该序列是环状序列时，我们应该如何求解呢？我们可以发现，环状序列相较于普通序列，
相当于添加了一个限制：普通序列中的第一个和最后一个数不能同时选。
这样一来，我们只需要对普通序列进行两遍动态即可得到答案，
第一遍动态规划中我们删去普通序列中的第一个数，表示我们不会选第一个数；
第二遍动态规划中我们删去普通序列中的最后一个数，表示我们不会选最后一个数。
将这两遍动态规划得到的结果去较大值，即为在环状序列上的答案。

作者：力扣官方题解
链接：https://leetcode.cn/problems/pizza-with-3n-slices/solutions/177086/3n-kuai-pi-sa-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/