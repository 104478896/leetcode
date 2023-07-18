/*请你设计一个可以解释字符串 command 的 Goal 解析器 。command 由 "G"、"()" 和/或 "(al)" 按某种顺序组成。Goal 解析器会将 "G" 解释为字符串 "G"、"()" 解释为字符串 "o" ，"(al)" 解释为字符串 "al" 。然后，按原顺序将经解释得到的字符串连接成一个字符串。

给你字符串 command ，返回 Goal 解析器 对 command 的解释结果。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/goal-parser-interpretation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string interpret(string command) {
        string ans;
        int len=command.size();
        for(int i=0;i<len;++i){
            if(command[i]=='G'){
                ans+=command[i];
            }else if(command[i]=='(' && command[i+1]==')'){
                ans+="o";
            }else if(command[i]=='('&&command[i+1]=='a'){
                ans+="al";
            }
            // cout<<ans<<endl;
        }
        return ans;
    }
};