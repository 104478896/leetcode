/*给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。*/
class Solution {
public:
    void reverse(string &s,int left,int right){
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
    string reverseWords(string s) {
        int len=s.size();
        int left=0;
        int right=0;
        for(int i=0;i<len;++i){
            if(s[i]==' '){
                right=i-1;
                reverse(s,left,right);
                left=i+1;
                continue;
            }
        }
        reverse(s,left,len-1);
        return s;
    }
};