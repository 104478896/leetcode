/*给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。

返回 合并后的字符串 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-strings-alternately
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1=word1.size();
        int len2=word2.size();
        string ans;
        int i=0;
        int j=0;
        while(i<len1||j<len2){
            if(i>=len1){
                ans+=word2[j++];
            }else if(j>=len2){
                ans+=word1[i++];
            }else if((i+j)%2==1){
                ans+=word2[j++];
            }else{
                ans+=word1[i++];
            }
        }
        return ans;
    }
};