/*给定一个包含非负整数的数组 nums ，返回其中可以组成三角形三条边的三元组个数。*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int len=nums.size();
        int ans=0;
        for(int i=0;i<len;++i){//第一条边
            for(int j=i+1;j<len;++j){//第二条边
                int left=j+1;
                int right=len-1;
                int k=j;
                while(left<=right){//符合以上两条边的最小边
                    int mid=left+(right-left)/2;
                    if(nums[mid]<nums[i]+nums[j]){
                        k=mid;
                        left=mid+1;
                    }else{
                        right=mid-1;
                    }
                }
                ans+=k-j;
            }
        }
        return ans;
    }
};