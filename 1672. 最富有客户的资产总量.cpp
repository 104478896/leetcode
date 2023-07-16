/*给你一个 m x n 的整数网格 accounts ，其中 accounts[i][j] 是第 i​​​​​​​​​​​​ 位客户在第 j 家银行托管的资产数量。返回最富有客户所拥有的 资产总量 。

客户的 资产总量 就是他们在各家银行托管的资产数量之和。最富有客户就是 资产总量 最大的客户。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/richest-customer-wealth
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        int m=accounts.size();
        int n=accounts[0].size();
        for(int i=0;i<m;++i){
            int temp=0;
            for(int j=0;j<n;++j){
                temp+=accounts[i][j];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};