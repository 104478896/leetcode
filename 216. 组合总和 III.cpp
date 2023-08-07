/*找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次 
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。*/
class Solution {
public:
    void dfs(int n,int k,int index,vector<vector<int>>&ans,vector<int>&path){
        int d=k-path.size();
        if(n<0||n>(2*index-d+1)*d/2){
            return;
        }
        if(d==0){
            ans.push_back(path);
            return;
        }

        for(int i=index;i>0;--i){
            path.push_back(i);
            dfs(n-i,k,i-1,ans,path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>path;
        dfs(n,k,9,ans,path);
        return ans;
    }
};