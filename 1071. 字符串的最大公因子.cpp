/*对于字符串 s 和 t，只有在 s = t + ... + t（t 自身连接 1 次或多次）时，我们才认定 “t 能除尽 s”。

给定两个字符串 str1 和 str2 。返回 最长字符串 x，要求满足 x 能除尽 str1 且 x 能除尽 str2 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/greatest-common-divisor-of-strings
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/*如果字符串str1和字符串str2有相同的最大公因子，代表str1+str2==str2+str1
两者有最大公因子，代表组成它们的子串长度时最大公因子
*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string ans="";
        if(str1+str2==str2+str1){
            int resLen=gcd(str1.size(),str2.size());
            for(int i=0;i<resLen;++i){
                ans.push_back(str1[i]);
            }
        }
        return ans;
    }
};


/*根据条件一步步判断*/
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int len1=str1.size();
        int len2=str2.size();
        int index1=0,index2=0;
        while(index1<len1&&index2<len2){
            //判断两个字符串是否含有不同字符相等，
            //含有不同字符意味着两个字符串不是由相同的子串组成
            if(str1[index1]!=str2[index2]){
                return "";
            }
            index1++;
            index2++;
        }
        //找出最大公因子，最大公因子的长度为两个字符串长度的最大公因子
        int resLen=gcd(len1,len2);
        string ans;
        for(int i=0;i<resLen;++i){//ans为最大公因子子串
            ans.push_back(str1[i]);
        }
        string temp=ans;
        //累加ans，并与str1和str2进行比较，如果长度超出str1或str2仍不相同，则返回空字符
        while(temp.size()<=len1){
            if(temp!=str1){
                temp+=ans;
                continue;
            }
            break;
        }
        if(temp.size()>len1){
            return "";
        }
        temp=ans;
        while(ans.size()<=len2){
            if(temp!=str2){
                temp+=ans;
                continue;
            }
            break;
        }
        if(temp.size()>len2){
            return "";
        }

        return ans;
    }
};