/*给你一个字符串 s，「k 倍重复项删除操作」将会从 s 中选择 k 个相邻且相等的字母，并删除它们，使被删去的字符串的左侧和右侧连在一起。

你需要对 s 重复进行无限次这样的删除操作，直到无法继续为止。

在执行完所有删除操作后，返回最终得到的字符串。

本题答案保证唯一。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<int> cnt;
        for(int i=0;i<s.size();++i){
            if(i==0||s[i]!=s[i-1]){//计数，当前栈顶元素为第一次遇到
                cnt.push(1);
            }else if(++cnt.top()==k){//如果计数等于k，删除两个指针之间的字符
                cnt.pop();
                s.erase(i-k+1,k);
                i=i-k;
            }
        }
        return s;
    }
};