/*给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。*/
class Solution {
public:
    vector<int>temp;
    vector<vector<int>>ans;
    void dfs(int cur,int n,int k){
        if(temp.size()+(n-cur+1)<k){
            return ;
        }
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(cur==n+1){
            return;
        }
        temp.push_back(cur);
        dfs(cur+1,n,k);
        temp.pop_back();
        dfs(cur+1,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(1,n,k);
        return ans;
    }
};