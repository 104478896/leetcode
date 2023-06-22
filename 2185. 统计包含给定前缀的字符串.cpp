/*给你一个字符串数组 words 和一个字符串 pref 。

返回 words 中以 pref 作为 前缀 的字符串的数目。

字符串 s 的 前缀 就是  s 的任一前导连续字符串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/counting-words-with-a-given-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        int len=pref.size();
        int num=words.size();
        for(int i=0;i<num;++i){
            if(len>words[i].size()){
                continue;
            }
            if(words[i].substr(0,len)==pref){
                ans++;
            }
        }
        return ans;
    }
};