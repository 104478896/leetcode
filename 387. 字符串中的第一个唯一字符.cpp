/*给定一个字符串 s ，找到 它的第一个不重复的字符，并返回它的索引 。如果不存在，则返回 -1 。*/
class Solution {
public:
    int firstUniqChar(string s) {

        int len=s.size();
        map<char,int>cnt;
        for(auto ch:s){
            cnt[ch]++;
        }
        for(int i=0;i<len;++i){
            if(cnt[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};