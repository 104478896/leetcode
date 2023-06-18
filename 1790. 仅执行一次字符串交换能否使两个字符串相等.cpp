/*给你长度相等的两个字符串 s1 和 s2 。一次 字符串交换 操作的步骤如下：选出某个字符串中的两个下标（不必不同），并交换这两个下标所对应的字符。

如果对 其中一个字符串 执行 最多一次字符串交换 就可以使两个字符串相等，返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-one-string-swap-can-make-strings-equal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // if(s1.size()!=s2.size()){
        //     return false;
        // }
        if(s1==s2){
            return true;
        }
        vector<int> diff;
        int len=s1.size();
        for(int i=0;i<len;++i){
            if(s1[i]!=s2[i]){
                diff.push_back(i);
            }
        }
        if(diff.size()>2||diff.size()==1){
            return false;
        }
        if(diff.size()==0){
            return true;
        }
        swap(s1[diff[0]],s1[diff[1]]);
        
        return s1==s2;

    }
};