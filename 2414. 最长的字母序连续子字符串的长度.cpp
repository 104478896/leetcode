/*字母序连续字符串 是由字母表中连续字母组成的字符串。换句话说，字符串 "abcdefghijklmnopqrstuvwxyz" 的任意子字符串都是 字母序连续字符串 。

例如，"abc" 是一个字母序连续字符串，而 "acb" 和 "za" 不是。
给你一个仅由小写英文字母组成的字符串 s ，返回其 最长 的 字母序连续子字符串 的长度。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/length-of-the-longest-alphabetical-continuous-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
//字母序连续字符串代表前一个字符比后一字符的ascall值小一
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int len=s.size();
        int ans=1;
        int left=0;
        for(int i=1;i<len;++i){
            if(s[i]!=s[i-1]+1){
                ans=max(i-left,ans);
                left=i;
            }
        }
        ans=max(len-left,ans);
        return ans;
    }
};