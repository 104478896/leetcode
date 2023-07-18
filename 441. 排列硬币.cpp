/*你总共有 n 枚硬币，并计划将它们按阶梯状排列。对于一个由 k 行组成的阶梯，其第 i 行必须正好有 i 枚硬币。阶梯的最后一行 可能 是不完整的。

给你一个数字 n ，计算并返回可形成 完整阶梯行 的总行数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/arranging-coins
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int arrangeCoins(int n) {
        int left=1;
        int right=n;
        long long mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(mid*(mid+1)<=(long)2*n){//等差为1的等差数列求和为: ((n+1)*n)/2;  
                //前几行的和小于等于硬币总和，变式将2向左乘
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return right;
    }
};