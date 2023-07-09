/*给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。*/
class Solution {
public:
    //额外数组
    void rotate(vector<int>& nums, int k) {
        int len=nums.size();
        vector<int> temp(len,0);
        k=k%len;
        for(int i=0;i<len;++i){
            temp[(i+k)%len]=nums[i];
        }
        nums=temp;
    }


    // //翻转数组
    // void reverse(vector<int>& nums,int start,int end){
    //     while(start<end){
    //         swap(nums[start],nums[end]);
    //         start++;
    //         end--;
    //     }
    // }
    // void rotate(vector<int>& nums, int k) {
    //     int len=nums.size();
    //     k=k%len;
    //     reverse(nums,0,len-1);
    //     reverse(nums,0,k-1);
    //     reverse(nums,k,len-1);

    // }
};