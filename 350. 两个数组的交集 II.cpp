/*给你两个整数数组 nums1 和 nums2 ，请你以数组形式返回两数组的交集。返回结果中每个元素出现的次数，应与元素在两个数组中都出现的次数一致（如果出现次数不一致，则考虑取较小值）。可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/intersection-of-two-arrays-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        //排序+双指针
        // vector<int> ans;
        // sort(nums1.begin(),nums1.end());
        // sort(nums2.begin(),nums2.end());
        // int index1=0;
        // int index2=0;
        // int len1=nums1.size();
        // int len2=nums2.size();
        // while(index1<len1&&index2<len2){
        //     if(nums1[index1]==nums2[index2]){
        //         ans.push_back(nums1[index1]);
        //         index1++;
        //         index2++;
        //     }else if(nums1[index1]<nums2[index2]){
        //         index1++;
        //     }else{
        //         index2++;
        //     }
        // }
        // return ans;
    

        // //哈希表
        // if(nums1.size()>nums2.size()){
        //     return intersect(nums2,nums1);//互换位置，保证数组长度较短的在前
        // }
        // map<int,int>cnt;
        // vector<int>ans;
        // for(auto num:nums1){
        //     cnt[num]++;
        // }
        // for(auto num:nums2){
        //     if(cnt.count(num)){
        //         ans.push_back(num);
        //         cnt[num]--;
        //         if(cnt[num]==0){
        //             cnt.erase(num);
        //         }
        //     }
        // }
        // return ans;


        //二分查找
        if(nums1.size()<nums2.size()){
            return intersect(nums2,nums1);
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>ans;
        int len1=nums1.size();
        int len2=nums2.size();
        int left=0;
        for(int i=0;i<len2;++i){
            int right=len1-1;
            int mid;
            while(left<=right){
                mid=left+(right-left)/2;
                if(nums1[mid]<nums2[i]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            if(nums1[left]==nums2[i]){
                ans.push_back(nums2[i]);
                left++;
            }
        }
        return ans;

    }
};