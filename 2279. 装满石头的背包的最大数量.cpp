/*现有编号从 0 到 n - 1 的 n 个背包。给你两个下标从 0 开始的整数数组 capacity 和 rocks 。第 i 个背包最大可以装 capacity[i] 块石头，当前已经装了 rocks[i] 块石头。另给你一个整数 additionalRocks ，表示你可以放置的额外石头数量，石头可以往 任意 背包中放置。

请你将额外的石头放入一些背包中，并返回放置后装满石头的背包的 最大 数量。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-bags-with-full-capacity-of-rocks
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>sub;
        int len=capacity.size();
        for(int i=0;i<len;++i){
            sub.push_back(capacity[i]-rocks[i]);
        }
        sort(sub.begin(),sub.end());
        int ans=0;
        int index=0;
        while(additionalRocks>0&&index<len){
            // ans++;
            // cout<<"index"<<sub[index]<<endl;
            // cout<<"add"<<additionalRocks<<endl;
            additionalRocks=additionalRocks-sub[index++];
            if(additionalRocks>=0){
                ans++;
            }
        }
        return ans;
    }
};