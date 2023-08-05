/*给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。*/
class Solution {
public:
    // //从输入角度回溯查找
    // void dfs(vector<int>& nums,int index,vector<vector<int>>& ans,vector<int>&path){
    //     if(index==nums.size()){
    //         ans.push_back(path);
    //         return;
    //     }
    //     dfs(nums,index+1,ans,path);
    //     path.push_back(nums[index]);
    //     dfs(nums,index+1,ans,path);
    //     path.pop_back();
    // }

    //从输出即答案角度回溯查找
    void dfs(vector<int>&nums,int index,vector<vector<int>>& ans,vector<int>&path){
        ans.push_back(path);
        for(int i=index;i<nums.size();++i){
            path.push_back(nums[i]);
            dfs(nums,i+1,ans,path);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(nums,0,ans,path);
        return ans;
    }
};