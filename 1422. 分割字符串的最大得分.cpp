/*给你一个由若干 0 和 1 组成的字符串 s ，请你计算并返回将该字符串分割成两个 非空 子字符串（即 左 子字符串和 右 子字符串）所能获得的最大得分。

「分割字符串的得分」为 左 子字符串中 0 的数量加上 右 子字符串中 1 的数量。

 */
 class Solution {
public:
    int maxScore(string s) {
        int temp=0;
        int len=s.size();
        if(s[0]=='0'){
            temp++;
        }
        for(int i=1;i<len;++i){
            if(s[i]=='1'){
                temp++;
            }
        }
        int score=temp;
        for(int i=1;i<len-1;++i){
            if(s[i]=='0'){
                temp++;
            }else{
                temp--;
            }
            score=max(temp,score);
        }
        return score;
    }
};