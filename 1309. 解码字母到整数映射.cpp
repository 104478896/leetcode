/*给你一个字符串 s，它由数字（'0' - '9'）和 '#' 组成。我们希望按下述规则将 s 映射为一些小写英文字符：

字符（'a' - 'i'）分别用（'1' - '9'）表示。
字符（'j' - 'z'）分别用（'10#' - '26#'）表示。 
返回映射之后形成的新字符串。

题目数据保证映射始终唯一。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/decrypt-string-from-alphabet-to-integer-mapping
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string freqAlphabets(string s) {
        int len=s.size();
        string ans;
        for(int i=len-1;i>=0;--i){
            if(s[i]=='#'&&(s[i-1]>='0'&&s[i-1]<='9')){
                int temp=(s[i-2]-'0')*10+s[i-1]-'0'-1;
                ans+='a'+temp;
                i=i-2;
            }else{
                ans+='a'+s[i]-'0'-1;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};