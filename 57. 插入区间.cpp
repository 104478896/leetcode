/*给你一个 无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left=newInterval[0];
        int right=newInterval[1];
        vector<vector<int>>ans;
        bool flag=false;
        for(auto interval:intervals){
            if(interval[0]>right){
                if(!flag){
                    ans.push_back({left,right});
                    flag=true;
                }
                ans.push_back(interval);
            }else if(interval[1]<left){
                ans.push_back(interval);
            }else{
                left=min(interval[0],left);
                right=max(interval[1],right);
            }
        }
        if(!flag){
            ans.push_back({left,right});
        }
        return ans;
    }
};