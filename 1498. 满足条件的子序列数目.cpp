/*给你一个整数数组 nums 和一个整数 target 。

请你统计并返回 nums 中能满足其最小元素与最大元素的 和 小于或等于 target 的 非空 子序列的数目。

由于答案可能很大，请将结果对 109 + 7 取余后返回。*/
class Solution {
public:
    static const int MOD=1e9+7;
    static const int MAX_N=1e5+5;
    int f[MAX_N];
    void pretreatment(){
        f[0]=1;
        for(int i=1;i<MAX_N;++i){
            f[i]=(long long)f[i-1]*2%MOD;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        pretreatment();
        int ans=0;
        int len=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<len&&nums[i]*2<=target;++i){
            int left=i;
            int right=len;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(nums[i]+nums[mid]>target){
                    right=mid-1;
                }else{
                    if(mid==len-1||nums[mid+1]+nums[i]>target){
                        left=mid;
                        break;
                    }else{
                        left=mid+1;
                    }
                }
            }
            
            int sum=(left>=i)?f[left-i]:0;
            ans=(ans+sum)%MOD;
        }
        return ans;
    }
};