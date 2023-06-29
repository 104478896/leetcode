/*给你一个整数 n 。如果 n 恰好有三个正除数 ，返回 true ；否则，返回 false 。

如果存在整数 k ，满足 n = k * m ，那么整数 m 就是 n 的一个 除数 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/three-divisors
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool isThree(int n) {
        int count=0;
        for(int i=1;i*i<=n;++i){
            if(n%i==0){
                if(i!=n/i){//判断是否是i的平方等于n，是的话加上一个整数，不是的话加上两个
                    count+=2;
                }else{
                    count+=1;
                }
            }
        }
        return count==3;
    }
};