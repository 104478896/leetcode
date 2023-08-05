/*给你两个正整数 a 和 b ，返回 a 和 b 的 公 因子的数目。

如果 x 可以同时整除 a 和 b ，则认为 x 是 a 和 b 的一个 公因子 。*/
class Solution {
public:
    int commonFactors(int a, int b) {
        int ans=1;
        int num=min(a,b);
        for(int i=2;i<=num;++i){
            if(a%i==0&&b%i==0){
                ans++;
            }
        }
        return ans;
    }
};