/*给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>stk;
        int len=temperatures.size();
        vector<int>ans(len,0);
        for(int i=0;i<len;++i){
            while(!stk.empty()&&temperatures[stk.top()]<temperatures[i]){
                int num=stk.top();
                ans[num]=i-num;
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};