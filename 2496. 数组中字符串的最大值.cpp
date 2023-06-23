/*一个由字母和数字组成的字符串的 值 定义如下：

如果字符串 只 包含数字，那么值为该字符串在 10 进制下的所表示的数字。
否则，值为字符串的 长度 。
给你一个字符串数组 strs ，每个字符串都只由字母和数字组成，请你返回 strs 中字符串的 最大值 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-value-of-a-string-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int isToF(string word){
        int len=word.size();
        for(int i=0;i<len;++i){
            if(word[i]<='z'&&word[i]>='a'){
                return len;
            }
        }
        int resLen=stoi(word);
        return resLen;
        
    }
    int maximumValue(vector<string>& strs) {
        int ans=0;
        int len=strs.size();
        for(int i=0;i<len;++i){
            ans=max(ans,isToF(strs[i]));
        }
        return ans;
    }
};