/*有效括号字符串为空 ""、"(" + A + ")" 或 A + B ，其中 A 和 B 都是有效的括号字符串，+ 代表字符串的连接。

例如，""，"()"，"(())()" 和 "(()(()))" 都是有效的括号字符串。
如果有效字符串 s 非空，且不存在将其拆分为 s = A + B 的方法，我们称其为原语（primitive），其中 A 和 B 都是非空有效括号字符串。

给出一个非空有效字符串 s，考虑将其进行原语化分解，使得：s = P_1 + P_2 + ... + P_k，其中 P_i 是有效括号字符串原语。

对 s 进行原语化分解，删除分解中每个原语字符串的最外层括号，返回 s 。*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        stack<char>stk;
        //s是一个有效括号字符串
        //每当遇到右括号时，将将栈顶元素弹出
        //如果当前的栈为空，则将不需要放入
        //否则将字符放入结果
        //删除外层括号，在栈中即为在栈为空的情况下的字符串去除首尾
        
        for(auto ch:s){
            if(ch==')'){
                stk.pop();
            }
            if(!stk.empty()){
                ans.push_back(ch);
            }
            if(ch=='('){
                stk.push(ch);
            }
        }
        return ans;
    }
};