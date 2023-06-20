/*给你一个字符串 num ，表示一个大整数。请你在字符串 num 的所有 非空子字符串 中找出 值最大的奇数 ，并以字符串形式返回。如果不存在奇数，则返回一个空字符串 "" 。

子字符串 是字符串中的一个连续的字符序列。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/largest-odd-number-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string largestOddNumber(string num) {
        string ans="";
        int len=num.size();
        for(int i=len-1;i>=0;--i){
            if((num[i]-'0')%2){
                for(int j=0;j<=i;++j){
                    ans.push_back(num[j]);
                } 
                return ans;
            }
        }
        
        return ans;
    }
};