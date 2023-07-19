/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？*/
class Solution {
public:
    int climbStairs(int n) {
        int a=0;
        int b=0;
        int ans=1;
        //滚动数组，f(x)=f(x-1)+f(x-2)
        for(int i=0;i<n;++i){
            a=b;
            b=ans;
            ans=a+b;
        }
        return ans;
    }
};