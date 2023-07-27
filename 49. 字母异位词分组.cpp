/*给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

 */
 class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>cnt;
        for(auto str:strs){
            //已排序后的字符串为键值，利用相同键值存储不同的异位字符串
            string temp=str;
            sort(temp.begin(),temp.end());
            cnt[temp].push_back(str);
        }
        //将每一个键值对中的值进行提取
        for(auto [key,val]:cnt){
            ans.push_back(val);
        }
        return ans;
    }
};