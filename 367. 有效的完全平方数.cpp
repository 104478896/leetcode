/*给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。

不能使用任何内置的库函数，如  sqrt 。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-perfect-square
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num==1){
            return num;
        }
        int left=1;
        int right=num/2;
        while(left<=right){
            long long mid=(right-left)/2+left;
            if(mid*mid==num){
                return true;
            }else if(mid*mid<num){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return false;
    }
};