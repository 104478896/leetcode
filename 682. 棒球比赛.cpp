/*你现在是一场采用特殊赛制棒球比赛的记录员。这场比赛由若干回合组成，过去几回合的得分可能会影响以后几回合的得分。

比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第 i 项操作，ops 遵循下述规则：

整数 x - 表示本回合新获得分数 x
"+" - 表示本回合新获得的得分是前两次得分的总和。题目数据保证记录此操作时前面总是存在两个有效的分数。
"D" - 表示本回合新获得的得分是前一次得分的两倍。题目数据保证记录此操作时前面总是存在一个有效的分数。
"C" - 表示前一次得分无效，将其从记录中移除。题目数据保证记录此操作时前面总是存在一个有效的分数。
请你返回记录中所有得分的总和。*/
class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum=0;
        vector<int>ans;
        for(auto str:operations){
            int len=ans.size()-1;
            if(str=="+"){
                ans.push_back(ans[len]+ans[len-1]);
            }else if(str=="C"){
                ans.erase(ans.begin()+len);
            }else if(str=="D"){
                ans.push_back(ans[len]*2);
            }else{
                ans.push_back(stoi(str));
            }
        }
        sum=accumulate(ans.begin(),ans.end(),0);
        return sum;
    }
};