/*给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串。*/
class Solution {
public:
    string toLowerCase(string s) {
        int len=s.size();
        for(int i=0;i<len;++i){
            if(s[i]>='A'&&s[i]<='Z'){
                s[i]+=32;
            }
        }
        return s;
    }
};