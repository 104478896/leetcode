/*给你一个字符串 s ，每 两个 连续竖线 '|' 为 一对 。换言之，第一个和第二个 '|' 为一对，第三个和第四个 '|' 为一对，以此类推。

请你返回 不在 竖线对之间，s 中 '*' 的数目。

注意，每个竖线 '|' 都会 恰好 属于一个对。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-asterisks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int countAsterisks(string s) {
        int ans=0;
        int count=0;
        int len=s.size();
        for(auto ch:s){
            if(ch=='|'){
                count++;
            }else if(ch=='*'&&count%2==0){
                ans++;
            }
        }
        return ans;
    }   
};