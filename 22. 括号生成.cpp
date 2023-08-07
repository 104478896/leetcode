/*数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。*/
class Solution {
public:
    void dfs(int m,int index,int left,vector<string>&ans,string path){
        if(m==index){
            ans.push_back(path);
            return;
        }
        if(left*2<m){//如果左括号的个数小于一半，可以继续放入左括号
            path.push_back('(');
            dfs(m,index+1,left+1,ans,path);
            path.pop_back();
        }
        if(index-left<left){//右括号的数量小于左括号的个数，可以继续放入右括号
            path.push_back(')');
            dfs(m,index+1,left,ans,path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int m=2*n;
        string path;
        
        dfs(m,0,0,ans,path);
        return ans;
    }
};