/*给你一个整数数组 nums 和一个正整数 k，请你判断是否可以把这个数组划分成一些由 k 个连续数字组成的集合。
如果可以，请返回 true；否则，返回 false。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/divide-array-in-sets-of-k-consecutive-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int len=nums.size();
        if(len%k!=0){
            return false;
        }
        map<int,int>count;
        sort(nums.begin(),nums.end());
        for(auto num:nums){
            count[num]++;
        }
        for(auto num:nums){
            if(count.find(num)==count.end()){
                continue;
            }
            for(int i=0;i<k;++i){
                if(count.find(num+i)==count.end()){
                    return false;
                }
                count[num+i]--;
                if(count[num+i]==0){
                    count.erase(num+i);
                }
            }
        }
        return true;
    }
};