/*nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/next-greater-element-i
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    // int next(int num,vector<int>&nums2){
    //     int len=nums2.size();
    //     for(int i=0;i<len;++i){
    //         if(num==nums2[i]){
    //             for(int j=i+1;j<len;++j){
    //                 if(nums2[j]>num){
    //                     return nums2[j];
    //                 }
    //             }
    //         }
    //     }
    //     return -1;
    // }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //暴力
        // vector<int> ans;
        // for(auto num:nums1){
        //     ans.push_back(next(num,nums2));
        // }
        // return ans;


        //单调栈+哈希
        map<int ,int>cnt;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;--i){//从右向左遍历nums2数组，找到下一个更大元素，存入哈希表，
        //栈中元素如果不为空且顶部元素小于当前查找元素，弹出栈顶，直到栈为空或栈顶元素大于查找元素
            while(!st.empty()&&st.top()<=nums2[i]){
                st.pop();
            }
            //如果当前的栈内为空，代表没有比查找元素大的，存入-1；否则存入栈顶元素
            cnt[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        vector<int>ans(nums1.size());
        for(int i=0;i<nums1.size();++i){
            ans[i]=cnt[nums1[i]];
        }
        return ans;



    }
};