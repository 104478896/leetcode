/*给你两个字符串 s 和 t 。在一步操作中，你可以给 s 或者 t 追加 任一字符 。

返回使 s 和 t 互为 字母异位词 所需的最少步骤数。

字母异位词 指字母相同但是顺序不同（或者相同）的字符串。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>cnt;
        for(auto ch:s){
            cnt[ch]++;
        }
        int ans=0;
        for(auto ch:t){
            if(cnt.find(ch)==cnt.end()||cnt[ch]==0){
                ans++;
            }else if(cnt[ch]>0){
                cnt[ch]--;
            }
        }
        for(auto [key,val]:cnt){
            ans+=val;
        }
        return ans;
    }
};