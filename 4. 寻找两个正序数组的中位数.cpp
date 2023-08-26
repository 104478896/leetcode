/*给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int m=nums1.size();
        int n=nums2.size();

        int total=(m+n+1)/2;  //中位数分割线左侧个数
        //在较短的一组数组中进行查找，保证在长的数组中有分割线
        //nums1[midS-1]<=nums2[midL]&&nums2[midL-1]<=nums1[midS]
        int left=0;
        int right=m;
        while(left<right){
            int midS=left+(right-left+1)/2;
            int midL=total-midS;    

            if(nums1[midS-1]>nums2[midL]){
                right=midS-1;
            }else{
                left=midS;
            }
        }

        //分割线
        int i=left;
        int j=total-i;
        int nums1LeftMax=i==0?INT_MIN:nums1[i-1];
        int nums1RightMin=i==m?INT_MAX:nums1[i];
        int nums2LeftMax=j==0?INT_MIN:nums2[j-1];
        int nums2RightMin=j==n?INT_MAX:nums2[j];

        double ans;
        if((m+n)%2==1){
            ans=max(nums1LeftMax,nums2LeftMax);
        }else{
            ans=(double)(max(nums1LeftMax,nums2LeftMax)+min(nums1RightMin,nums2RightMin))/2;
        }
        return ans;
    }
};