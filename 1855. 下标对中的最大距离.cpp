/*给你两个 非递增 的整数数组 nums1​​​​​​ 和 nums2​​​​​​ ，数组下标均 从 0 开始 计数。

下标对 (i, j) 中 0 <= i < nums1.length 且 0 <= j < nums2.length 。如果该下标对同时满足 i <= j 且 nums1[i] <= nums2[j] ，则称之为 有效 下标对，该下标对的 距离 为 j - i​​ 。​​

返回所有 有效 下标对 (i, j) 中的 最大距离 。如果不存在有效下标对，返回 0 。

一个数组 arr ，如果每个 1 <= i < arr.length 均有 arr[i-1] >= arr[i] 成立，那么该数组是一个 非递增 数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/maximum-distance-between-a-pair-of-values
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int ans=0;
        for(int i=0;i<len1;++i){
            int left=i;
            int right=nums2.size()-1;
            int mid;
            while(left<=right){
                mid=left+(right-left)/2;
                if(nums2[mid]<nums1[i]){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            if(i<=right){
                ans=max(right-i,ans);
            }
        }
        return ans;
    }
};