/*给你一个字符串 s 和一个字符 c ，且 c 是 s 中出现过的字符。

返回一个整数数组 answer ，其中 answer.length == s.length 且 answer[i] 是 s 中从下标 i 到离它 最近 的字符 c 的 距离 。

两个下标 i 和 j 之间的 距离 为 abs(i - j) ，其中 abs 是绝对值函数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/shortest-distance-to-a-character
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int compare(vector<int> index,int num){
        int len=index.size();
        int res=abs(index[0]-num);
        for(int i=1;i<len;++i){

            res=min(res,abs(index[i]-num));
            // cout<<temp<<endl;
        }
        return res;
    }
    vector<int> shortestToChar(string s, char c) {
        int len=s.size();
        vector<int>index;
        for(int i=0;i<len;++i){
            if(s[i]==c){
                index.push_back(i);
                // cout<<i<<endl;
            }
        }
        vector<int>ans;
        for(int i=0;i<len;++i){
            ans.push_back(compare(index,i));
        }
        return ans;

    }
};