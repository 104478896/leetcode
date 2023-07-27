/*给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。*/
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenS=s.size();
        int lenP=p.size();
        vector<int>ans;
        if(lenS<lenP){
            return ans;
        }
        vector<int> countS(26);
        vector<int> countP(26);
        for(int i=0;i<lenP;++i){
            countP[p[i]-'a']++;
            countS[s[i]-'a']++;
        }
        
        if(countS==countP){
            ans.push_back(0);
        }

        for(int i=0;i<lenS-lenP;++i){
            countS[s[i]-'a']--;
            countS[s[i+lenP]-'a']++;
            if(countS==countP){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};