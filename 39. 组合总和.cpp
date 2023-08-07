/*给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。

 */
 class Solution {
public:
    void dfs(vector<int>&candidates,int index,int target,vector<vector<int>>&ans,vector<int>&path){
        if(index==candidates.size()){
            return;
        }
        if(target==0){
            ans.push_back(path);
            return;
        }
        dfs(candidates,index+1,target,ans,path);
        if(target-candidates[index]>=0){
            path.push_back(candidates[index]);
            dfs(candidates,index,target-candidates[index],ans,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(candidates,0,target,ans,path);
        return ans;
    }
};