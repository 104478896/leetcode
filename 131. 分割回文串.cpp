/*给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。*/
class Solution {
public:
    bool helper(int left,int right,string s){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    void dfs(string s,int index,vector<vector<string>>&ans,vector<string>&path){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();++i){
            
            if(helper(index,i,s)){
                path.push_back(s.substr(index,i-index+1));
                dfs(s,i+1,ans,path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        int len=s.size();
        vector<string>path;
        dfs(s,0,ans,path);
        return ans;
    }
};