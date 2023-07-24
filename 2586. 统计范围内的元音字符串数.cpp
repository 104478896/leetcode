/*给你一个下标从 0 开始的字符串数组 words 和两个整数：left 和 right 。

如果字符串以元音字母开头并以元音字母结尾，那么该字符串就是一个 元音字符串 ，其中元音字母是 'a'、'e'、'i'、'o'、'u' 。

返回 words[i] 是元音字符串的数目，其中 i 在闭区间 [left, right] 内。*/
class Solution {
public:
    bool helper(string word){
        int len=word.size()-1;
        if((word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u')&&
        (word[len]=='a'||word[len]=='e'||word[len]=='i'||word[len]=='o'||word[len]=='u')){
            return true;
        }
        return false;
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans=0;
        for(int i=left;i<=right;++i){
            if(helper(words[i])){
                ans++;
            }
        }
        return ans;
    }
};