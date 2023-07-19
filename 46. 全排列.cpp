/*给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。*/
class Solution {
public:
    void backFind(vector<vector<int>>&ans,vector<int>&nums,int start){
        if(start==nums.size()){
            ans.push_back(nums);
            return ;
        }
        int len=nums.size();
        //每次从起始位置开始填入坐标，即将起始位置的数于之后的每一个数进行交换，
        //保证之后的每一个数都在这个位置上出现一次
        //当起始位置等于数组长度时，代表已经将当前的可能全部填入，可以压入结果中
        for(int i=start;i<len;++i){
            //nums是全局变量，更换后为保证结果的不重复或缺少，需要在操作完成后交换回去
            swap(nums[i],nums[start]);
            backFind(ans,nums,start+1);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        backFind(ans,nums,0);
        return ans;
    }
};