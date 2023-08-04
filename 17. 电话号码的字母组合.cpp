/*给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。*/
class Solution {
public:
    vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(string digits,int index,vector<string>&ans,string& path){
        if(index==digits.size()){
            ans.push_back(path);
            return;
        }
        for(auto ch:mapping[digits[index]-'0']){
            path[index]=ch;
            dfs(digits,index+1,ans,path);
        }
    }
    vector<string> letterCombinations(string digits) {
        int len=digits.size();
        if(len==0){
            return {};
        }
        
        vector<string>ans;
        string path(len,0);
        dfs(digits,0,ans,path);
        return ans;
    }
};