/*给你两个长度相等的字符串 s 和 t。每一个步骤中，你可以选择将 t 中的 任一字符 替换为 另一个字符。

返回使 t 成为 s 的字母异位词的最小步骤数。

字母异位词 指字母相同，但排列不同（也可能相同）的字符串。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-number-of-steps-to-make-two-strings-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>countS;
        for(auto ch:s){
            countS[ch]++;
        }
        int ans=0;
        for(auto ch:t){
            if(countS.find(ch)!=countS.end()&&countS[ch]>0){
                countS[ch]--;
            }else{
                ans++;
            }
        }
        return ans;
    }
};