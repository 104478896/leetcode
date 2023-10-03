/*给你一个下标从 0 开始的二维整数数组 flowers ，其中 flowers[i] = [starti, endi] 表示第 i 朵花的 花期 从 starti 到 endi （都 包含）。同时给你一个下标从 0 开始大小为 n 的整数数组 people ，people[i] 是第 i 个人来看花的时间。

请你返回一个大小为 n 的整数数组 answer ，其中 answer[i]是第 i 个人到达时在花期内花的 数目 。

 */
 class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        int len=flowers.size();
        vector<int>starts;
        vector<int>ends;
        for(auto f:flowers){
            starts.push_back(f[0]);
            ends.push_back(f[1]);
        }
        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());
        vector<int>ans;
        for(auto p:people){
            ans.push_back((upper_bound(starts.begin(),starts.end(),p)-starts.begin())-
                            (lower_bound(ends.begin(),ends.end(),p)-ends.begin()));
        }
        return ans;
    }
};