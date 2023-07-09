/*给你一个由英文字母组成的字符串 s ，请你找出并返回 s 中的 最好 英文字母。返回的字母必须为大写形式。如果不存在满足条件的字母，则返回一个空字符串。

最好 英文字母的大写和小写形式必须 都 在 s 中出现。

英文字母 b 比另一个英文字母 a 更好 的前提是：英文字母表中，b 在 a 之 后 出现

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/greatest-english-letter-in-upper-and-lower-case
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string greatestLetter(string s) {
        string ans;
        set<char>cnt;
        for(auto ch:s){
            cnt.insert(ch);
        }
        for(int i=25;i>=0;--i){
            if(cnt.count('a'+i)&&cnt.count('A'+i)){
                ans+='A'+i;
                break;
            }
        }
        return ans;
    }
};