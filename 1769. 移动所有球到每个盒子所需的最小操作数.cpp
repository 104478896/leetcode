/*有 n 个盒子。给你一个长度为 n 的二进制字符串 boxes ，其中 boxes[i] 的值为 '0' 表示第 i 个盒子是 空 的，而 boxes[i] 的值为 '1' 表示盒子里有 一个 小球。

在一步操作中，你可以将 一个 小球从某个盒子移动到一个与之相邻的盒子中。第 i 个盒子和第 j 个盒子相邻需满足 abs(i - j) == 1 。注意，操作执行后，某些盒子中可能会存在不止一个小球。

返回一个长度为 n 的数组 answer ，其中 answer[i] 是将所有小球移动到第 i 个盒子所需的 最小 操作数。

每个 answer[i] 都需要根据盒子的 初始状态 进行计算。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/minimum-number-of-operations-to-move-all-balls-to-each-box
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int count(string boxes,int index){
        int len=boxes.size();
        int res=0;
        for(int i=0;i<len;++i){
            if(i==index){
                continue;
            }
            if(boxes[i]=='1'){
                res+=abs(i-index);
            }
        }
        // cout<<res<<endl;
        return res;
    }
    vector<int> minOperations(string boxes) {
        vector<int>ans;
        int len=boxes.size();
        for(int i=0;i<len;++i){
            ans.push_back(count(boxes,i));
        }
        return ans;
    }
};