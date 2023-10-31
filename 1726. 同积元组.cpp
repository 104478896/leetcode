/*给你一个由 不同 正整数组成的数组 nums ，请你返回满足 a * b = c * d 的元组 (a, b, c, d) 的数量。其中 a、b、c 和 d 都是 nums 中的元素，且 a != b != c != d 。*/
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int len=nums.size();
        map<int,int>cnt;
        int ans=0;
        for(int i=0;i<len;++i){
            for(int j=i+1;j<len;++j){
                cnt[nums[i]*nums[j]]++;
            }
        }
        for(auto [key,val]:cnt){
            ans+=val*(val-1)*4;
        }
        return ans;
    }
};