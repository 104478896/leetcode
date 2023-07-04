/*给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/kth-largest-element-in-an-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        map<int,int>cnt;
        for(auto num:nums){
            cnt[num]++;
        }
        int pos=nums.size()-k+1;
        int temp=0;
        for(auto [key,val]:cnt){
            temp+=val;
            if(temp>=pos){
                return key;
            }
        }

        return nums[0];
    }
};