/*给你一个 仅 由字符 'a' 和 'b' 组成的字符串  s 。如果字符串中 每个 'a' 都出现在 每个 'b' 之前，返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-all-as-appears-before-all-bs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    bool checkString(string s) {
        int len=s.size();
        int indexB=len;
        int indexA=-1;
        
        for(int i=0;i<len;++i){
            if(s[i]=='b'){
                indexB=i;
                break;
            }
        }
        for(int i=len-1;i>=0;--i){
            if(s[i]=='a'){
                indexA=i;
                break;
            }
        }
        return indexB>indexA;
    }
};