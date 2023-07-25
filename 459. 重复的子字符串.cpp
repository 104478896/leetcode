/*给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。*/
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len=s.size();
        int flag=1;
        for(int i=1;i<=len/2;++i){
            if(len%i==0){
                flag=0;
                for(int j=i;j<len;++j){
                    if(s[j]!=s[j-i]){
                        flag=1;
                        break;
                    }
                }
            }
            if(flag==0){
                return true;
            }
             
        }
        
        return false;
    }
};