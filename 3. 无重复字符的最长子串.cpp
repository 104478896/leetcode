/*给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();//字符串s的长度
        map<char,int>cont;//哈希表统计，统计子字符串是否有重复
        int left=0;//左指针，指向子字符串左端
        int ans=0;//最长长度
        for(int right=0;right<len;++right){
            cont[s[right]]++;//右端扩一位，
            while(cont[s[right]]>1){
                //当右端的指针右移时，出现重复数组，将左指针不断右移并将存在哈希表中的字符数减一，
                //直到扩充位的字符不重复
                cont[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }

        return ans;
    }
};