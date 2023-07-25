/*给你一个正整数数组 nums 。每一次操作中，你可以从 nums 中选择 任意 一个数并将它减小到 恰好 一半。（注意，在后续操作中你可以对减半过的数继续执行操作）

请你返回将 nums 数组和 至少 减少一半的 最少 操作数。*/
class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>que(nums.begin(),nums.end());
        int len=nums.size();
        int ans=0;
        double sum=0;
        for(int i=0;i<len;++i){
            sum+=nums[i];
        }
        double tempSum=sum;
        while(tempSum>sum/2){
            double temp=que.top()/2;
            // cout<<que.top()<<endl;
            que.pop();
            tempSum-=temp;
            que.push(temp);
            ans++;
            
        }
        return ans;
    }
};