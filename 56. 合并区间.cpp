/*以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int len=intervals.size();
        if(len<=1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<len;++i){
            int start=intervals[i][0];
            int end=intervals[i][1];
            if(ans.size()==0||ans.back()[1]<start){
                ans.push_back({start,end});
            }else{
                ans.back()[1]=max(ans.back()[1],end);
            }
        }
        return ans;
    }
};