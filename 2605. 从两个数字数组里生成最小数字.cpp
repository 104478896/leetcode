/*给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，请你返回 最小 的数字，两个数组都 至少 包含这个数字的某个数位。*/
class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>cnt;
        for(auto num:nums1){
            cnt[num]++;
        }
        int ans=10;
        for(auto num:nums2){
            if(cnt.find(num)!=cnt.end()){
                ans=min(ans,num); 
            }
        }
        if(ans!=10){
            return ans;
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        if(nums1[0]>nums2[0]){
            ans=nums2[0]*10+nums1[0];
        }else{
            ans=nums1[0]*10+nums2[0];
        }
        return ans;
    }
};