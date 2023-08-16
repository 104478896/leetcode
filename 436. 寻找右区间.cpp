/*给你一个区间数组 intervals ，其中 intervals[i] = [starti, endi] ，且每个 starti 都 不同 。

区间 i 的 右侧区间 可以记作区间 j ，并满足 startj >= endi ，且 startj 最小化 。注意 i 可能等于 j 。

返回一个由每个区间 i 的 右侧区间 在 intervals 中对应下标组成的数组。如果某个区间 i 不存在对应的 右侧区间 ，则下标 i 处的值设为 -1 。*/
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int>ans;
        map<int,int>cnt;//每个间隔的起点均不相同
        int index=0;
        for(auto num:intervals){
            cnt[num[0]]=index;
            index++;
        }
        for(auto v:intervals){
            auto it=cnt.lower_bound(v[1]);
            if(it!=cnt.end()){
                ans.push_back((*it).second);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};