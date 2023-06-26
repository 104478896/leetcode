/*给你一个三位数整数 n 。

如果经过以下修改得到的数字 恰好 包含数字 1 到 9 各一次且不包含任何 0 ，那么我们称数字 n 是 迷人的 ：

将 n 与数字 2 * n 和 3 * n 连接 。
如果 n 是迷人的，返回 true，否则返回 false 。

连接 两个数字表示把它们首尾相接连在一起。比方说 121 和 371 连接得到 121371 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-the-number-is-fascinating
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool isFascinating(int n) {
        // int temp=n;
        string ans=to_string(n);
        ans+=to_string(2*n);
        ans+=to_string(3*n);

        if(ans.size()>9){
            return false;
        }
        map<int,int>count;
        for(auto ch:ans){
            count[ch]++;

        }
        
        if(count.find('0')!=count.end()||count.size()!=9){
            return false;
        }
        return true;
    }
};