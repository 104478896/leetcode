/*给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>cnt;
        for(auto word:wordDict){
            cnt.insert(word);
        }
        int len=s.size();
        vector<bool>dp(len+1);
        dp[0]=true;
        for(int i=1;i<=len;++i){
            for(int j=0;j<i;++j){
                if(dp[j]&&cnt.find(s.substr(j,i-j))!=cnt.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[len];
    }
};