/*给定两个字符串 s 和 t ，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。*/
class Solution {
public:
    char findTheDifference(string s, string t) {
        
        //哈希表计数
        // map<char,int>cnt;
        // char ans;
        // for(auto ch:t){
        //     cnt[ch]++;
        // }
        // for(auto ch:s){
        //     cnt[ch]--;
        //     if(cnt[ch]==0){
        //         cnt.erase(ch);
        //     }
        // }
        // ans=cnt.begin()->first;

        // return ans;

        //本质是找奇数位出现的字符,利用异或运算
        char ans=0;
        for(auto ch:s+t){
            ans^=ch;
        }
        return ans;

    }
};