/*给你一个下标从 0 开始的二维整数数组 nums 。一开始你的分数为 0 。你需要执行以下操作直到矩阵变为空：

矩阵中每一行选取最大的一个数，并删除它。如果一行中有多个最大的数，选择任意一个并删除。
在步骤 1 删除的所有数字中找到最大的一个数字，将它添加到你的 分数 中。
请你返回最后的 分数 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sum-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int row=nums.size();
        int col=nums[0].size();
        int ans=0;
        for(int i=0;i<row;++i){
            sort(nums[i].begin(),nums[i].end());
        }
        for(int j=0;j<col;++j){
            vector<int>temp;
            for(int i=0;i<row;++i){
                temp.push_back(nums[i].back());
                nums[i].pop_back();
            }
            ans+=*max_element(temp.begin(),temp.end());
        }
        return ans;
    }
};