/*给你一个下标从 0 开始的字符串 details 。details 中每个元素都是一位乘客的信息，信息用长度为 15 的字符串表示，表示方式如下：

前十个字符是乘客的手机号码。
接下来的一个字符是乘客的性别。
接下来两个字符是乘客的年龄。
最后两个字符是乘客的座位号。
请你返回乘客中年龄 严格大于 60 岁 的人数。*/
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans=0;
        for(auto str:details){
            if(((str[11]-'0')*10+(str[12]-'0'))>60){
                ans++;
            }
        }
        return ans;
    }
};