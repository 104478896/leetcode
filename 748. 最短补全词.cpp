/*给你一个字符串 licensePlate 和一个字符串数组 words ，请你找出 words 中的 最短补全词 。

补全词 是一个包含 licensePlate 中所有字母的单词。忽略 licensePlate 中的 数字和空格 。不区分大小写。如果某个字母在 licensePlate 中出现不止一次，那么该字母在补全词中的出现次数应当一致或者更多。

例如：licensePlate = "aBc 12c"，那么它的补全词应当包含字母 'a'、'b' （忽略大写）和两个 'c' 。可能的 补全词 有 "abccdef"、"caaacab" 以及 "cbca" 。

请返回 words 中的 最短补全词 。题目数据保证一定存在一个最短补全词。当有多个单词都符合最短补全词的匹配条件时取 words 中 第一个 出现的那个。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shortest-completing-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<string>ans;
        map<char,int>count;//统计licensePlate中的字母个数
        for(auto ch:licensePlate){
            if(isalpha(ch)){//判断是否为字母
                ch=tolower(ch);//将字母转为小写字母
                count[ch]++;  //统计个数
            }
        }
        int len=words.size();
        for(int i=0;i<len;++i){
            map<char,int>temp;//临时存储当前words中的一个字符串的字母个数
            for(auto ch:words[i]){
                temp[ch]++;
            }
            int flag=1;
            for(auto [key,val]:count){//如果该字符串中没有应该有的字符或者是小于应有的数量，flag置为0
                if(temp.find(key)==temp.end()||temp[key]<val){
                    flag=0;
                    break;
                }
            }
            //符合条件的存入字符串数组
            if(flag){
                ans.push_back(words[i]);
            }
        }
        string res=ans[0];
        for(auto str:ans){//找到第一个长度最短的符合条件的字符串
            if(res.size()>str.size()){
                res=str;
            }
        }
        return res;
    }
};