/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size()!=t.size()){
        //     return false;
        // }
        // map<char,int>cnt;
        // for(auto ch:s){
        //     cnt[ch]++;
        // }
        // for(auto ch:t){
        //     if(cnt.count(ch)){
        //         cnt[ch]--;
        //         if(cnt[ch]==0){
        //             cnt.erase(ch);
        //         }
        //     }else{
        //         return false;
        //     }
        // }
        // return true;


        //数组模拟
        if(s.size()!=t.size()){
            return false;
        }
        vector<int> sCnt(26);
        vector<int> tCnt(26);
        for(auto ch:s){
            sCnt[ch-'a']++;
        }
        for(auto ch:t){
            tCnt[ch-'a']++;
        }
        for(int i=0;i<26;++i){
            if(sCnt[i]!=tCnt[i]){
                return false;
            }
        }
        return true;
    }
};