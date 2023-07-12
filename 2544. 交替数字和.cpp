/*给你一个正整数 n 。n 中的每一位数字都会按下述规则分配一个符号：

最高有效位 上的数字分配到 正 号。
剩余每位上数字的符号都与其相邻数字相反。
返回所有数字及其对应符号的和。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/alternating-digit-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int alternateDigitSum(int n) {
        string str=to_string(n);
        int ans=str[0]-'0';
        int len=str.size();
        int temp=-1;
        for(int i=1;i<len;++i){
            ans+=(temp*(str[i]-'0'));
            temp*=-1;
        }
        return ans;
    }
};