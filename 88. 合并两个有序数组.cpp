/*给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。

请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。

注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-sorted-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1=0;
        int index2=0;
        int nums[m+n];
        int cnt=0;
        while(index1<m||index2<n){
            if(index1==m){
                nums[cnt++]=nums2[index2++];
            }else if(index2==n){
                nums[cnt++]=nums1[index1++];
            }else if(nums1[index1]<=nums2[index2]){
                nums[cnt++]=nums1[index1++];
            }else{
                nums[cnt++]=nums2[index2++];
            }
        }
        for(int i=0;i<m+n;++i){
            nums1[i]=nums[i];
        }

    }
};