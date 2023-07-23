/*给你一个字符串数组 words 和一个字符 separator ，请你按 separator 拆分 words 中的每个字符串。

返回一个由拆分后的新字符串组成的字符串数组，不包括空字符串 。

注意

separator 用于决定拆分发生的位置，但它不包含在结果字符串中。
拆分可能形成两个以上的字符串。
结果字符串必须保持初始相同的先后顺序。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/split-strings-by-separator
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;
        for(auto str:words){
            string temp;
            for(auto ch:str){
                if(ch==separator&&temp.size()!=0){
                    ans.push_back(temp);
                    temp="";
                }else if(ch==separator){
                    continue;
                }else{
                    temp+=ch;
                }
            }
            if(temp.size()!=0){
                ans.push_back(temp);
                temp="";
            }
        }
        return ans;
    }
};