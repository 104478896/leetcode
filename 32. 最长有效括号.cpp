/*给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。*/
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>stk;
        int ans=0;
        int len = s.size();
        stk.push(-1);//记录上一个连续括号中最后一个没有被匹配的右括号的下标
        for(int i=0;i<len;++i){
            if(s[i]=='('){
                stk.push(i);
            }else{
                stk.pop();
                if(stk.empty()){
                    stk.push(i);
                }else{
                    ans=max(ans,i-stk.top());
                }
            }
        }
        return ans;
    }
};