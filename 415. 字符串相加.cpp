/*给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和并同样以字符串形式返回。

你不能使用任何內建的用于处理大整数的库（比如 BigInteger）， 也不能直接将输入的字符串转换为整数形式。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ans;
        int len1=num1.size();
        int len2=num2.size();
        int index1=len1-1;
        int index2=len2-1;
        int cnt=0;
        while(index1>=0||index2>=0){
            char temp;
            if(index1<0){
                temp=(cnt+(num2[index2]-'0'))%10+'0';
                cnt=(cnt+(num2[index2]-'0'))/10;
                ans.push_back(temp);
                index2--;
            }else if(index2<0){
                temp=(cnt+(num1[index1]-'0'))%10+'0';
                cnt=(cnt+(num1[index1]-'0'))/10;
                ans.push_back(temp);
                index1--;
            }else{
                char temp=(cnt+(num1[index1]-'0')+(num2[index2]-'0'))%10+'0';
                ans.push_back(temp);
                cnt=(cnt+(num1[index1]-'0')+(num2[index2]-'0'))/10;
                index1--;
                index2--;
            }
        }
        
        if(cnt>0){
            ans.push_back(cnt+'0');
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};