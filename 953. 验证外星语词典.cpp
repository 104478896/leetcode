/*某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/verifying-an-alien-dictionary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        map<char,int>cnt;
        for(int i=0;i<26;++i){
            cnt[order[i]]=i;
        }
        int len=words.size();
        for(int i=1;i<len;++i){
            string str1=words[i-1];
            string str2=words[i];
            int lengh1=str1.size();
            int lengh2=str2.size();
            int index1=0;
            int index2=0;
            while(index1<lengh1||index2<lengh2){
                if(index1>=lengh1){
                    break;
                }else if(index2>=lengh2){
                    return false;
                }
                if(cnt[str1[index1]]<cnt[str2[index2]]){
                    break;
                }else if(cnt[str1[index1]]>cnt[str2[index2]]){
                    return false;
                }else{
                    index1++;
                    index2++;
                }

            }
        }
        return true;
    }
};