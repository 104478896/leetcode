/*给你两个字符串 s1 和 s2 ，写一个函数来判断 s2 是否包含 s1 的排列。如果是，返回 true ；否则，返回 false 。

换句话说，s1 的排列之一是 s2 的 子串 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/permutation-in-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int len1=s1.size();
        int len2=s2.size();
        if(len1>len2){
            return false;
        }
        vector<int> cnt(26);
        for(int i=0;i<len1;++i){
            cnt[s1[i]-'a']--;
            cnt[s2[i]-'a']++;
        }
        int diff=0;//统计差异字符
        for(auto num:cnt){
            if(num!=0){
                diff++;
            }
        }
        if(diff==0){//没有差异，返回true
            return true;
        }
        for(int i=len1;i<len2;++i){
            int left=s2[i-len1]-'a';
            int right=s2[i]-'a';
            if(left==right){
                continue;
            }
            if(cnt[right]==0){
                diff++;
            }
            cnt[right]++;
            if(cnt[right]==0){
                diff--;
            }
            if(cnt[left]==0){
                diff++;
            }
            cnt[left]--;
            if(cnt[left]==0){
                diff--;
            }

            if(diff==0){
                return true;
            }
        }

        return false;
    }
};