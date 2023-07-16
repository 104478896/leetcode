/*给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/ransom-note
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote==magazine){
            return true;
        }
        
        map<char,int>cnt;
        for(auto ch:magazine){
            cnt[ch]++;
        }
        for(auto ch:ransomNote){
            if(cnt.count(ch)){
                cnt[ch]--;
                if(cnt[ch]==0){
                    cnt.erase(ch);
                }
            }else{
                return false;
            }
        }
        return true;
    }
};