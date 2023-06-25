/*给定一个字符串 s ，通过将字符串 s 中的每个字母转变大小写，我们可以获得一个新的字符串。

返回 所有可能得到的字符串集合 。以 任意顺序 返回输出。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/letter-case-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    //深度优先遍历
    //当遇到数字时，直接跳过
    //当遇到字符时，将当前字符更改大小写，继续向后遍历，如果当前已遍历长度与字符串长度相同，跳出
    //字符更改大小写遍历结束后，将大小写状态还原，继续向后遍历
    void dfs(string &s,int index,vector<string>& ans){
        int len=s.size();
        while(index<len&&!(isalpha(s[index]))){
            index++;
        }
        if(index==len){
            ans.push_back(s);
            // return;
        }else{
            s[index]^=32;
            dfs(s,index+1,ans);
            s[index]^=32;
            dfs(s,index+1,ans);
        }
        
    }   
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        dfs(s,0,ans);
        return ans;
    }
};