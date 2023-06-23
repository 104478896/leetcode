/*给你一个正整数 n ，找出满足下述条件的 中枢整数 x ：

1 和 x 之间的所有元素之和等于 x 和 n 之间所有元素之和。
返回中枢整数 x 。如果不存在中枢整数，则返回 -1 。题目保证对于给定的输入，至多存在一个中枢整数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-pivot-integer
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int pivotInteger(int n) {
        //求中枢整数，等差数列中前x项等于后n-x项
        //由等差数列推到得出，sum(1,x)==sum(x,n),即((1+x)*x)/2==((x+n)*(n-x+1))/2
        //化简得出：x^2=(n^2+n)/2
        //x若为整数代表该数为中枢整数
        int sum=(n*(n+1))/2;
        int x=sqrt(sum);
        if(x*x==sum){
            return x;
        }
        return -1;

    }
};