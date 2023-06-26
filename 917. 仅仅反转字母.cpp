/*给你一个字符串 s ，根据下述规则反转字符串：

所有非英文字母保留在原有位置。
所有英文字母（小写或大写）位置反转。
返回反转后的 s 。*/
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int left=0;
        int right=s.size()-1;
        int len=s.size();
        while(left<right){
            if((!isalpha(s[left]))&&(!isalpha(s[right]))){
                left++;
                right--;
            }else if(isalpha(s[left])&&(!isalpha(s[right]))){
                right--;
            }else if((!isalpha(s[left]))&&isalpha(s[right])){
                left++;
            }else{
                swap(s[left],s[right]);
                left++;
                right--;
            }

            
        }
        return s;
    }
};