/*给你一个字符串 s，请你对 s 的子串进行检测。

每次检测，待检子串都可以表示为 queries[i] = [left, right, k]。我们可以 重新排列 子串 s[left], ..., s[right]，并从中选择 最多 k 项替换成任何小写英文字母。 

如果在上述检测过程中，子串可以变成回文形式的字符串，那么检测结果为 true，否则结果为 false。

返回答案数组 answer[]，其中 answer[i] 是第 i 个待检子串 queries[i] 的检测结果。

注意：在替换时，子串中的每个字母都必须作为 独立的 项进行计数，也就是说，如果 s[left..right] = "aaa" 且 k = 2，我们只能替换其中的两个字母。（另外，任何检测都不会修改原始字符串 s，可以认为每次检测都是独立的）

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/can-make-palindrome-from-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int len=s.size();
        int que=queries.size();
        vector<array<int,26>> sum(len+1);
        //利用前缀和获取子串中各字符的奇偶情况
        for(int i=0;i<len;++i){
            sum[i+1]=sum[i];
            sum[i+1][s[i]-'a']++;
        }
        vector<bool>ans;
        for(int i=0;i<que;++i){
            auto& temp=queries[i];
            int left=temp[0];
            int right=temp[1];
            int k=temp[2];
            int num=0;
            for(int j=0;j<26;++j){
                num+=(sum[right+1][j]-sum[left][j])%2;
            }
            if(num/2<=k){
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};