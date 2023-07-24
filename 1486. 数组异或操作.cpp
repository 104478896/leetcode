/*给你两个整数，n 和 start 。

数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。

请返回 nums 中所有元素按位异或（XOR）后得到的结果。*/
class Solution {
public:
    int xorOperation(int n, int start) {
        int ans=start;
        for(int i=1;i<n;++i){
            ans^=(start+2*i);
        }
        return ans;
    }
};