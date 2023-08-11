/*给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int len=nums.size();
        priority_queue<pair<int,int>>que;
        for(int i=0;i<k;++i){
            que.push({nums[i],i});
        }
        vector<int>ans;
        ans.push_back(que.top().first);
        for(int i=k;i<len;++i){
            que.push({nums[i],i});
            while(que.top().second<=i-k){
                //当优先队列中的最大值的下标在窗口左侧，弹出
                //直到最大值位于滑动窗口中
                que.pop();
            }
            ans.push_back(que.top().first);
        }
        return ans;
    }
};