/*编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」 定义为：

对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int next(int n){
        int sum=0;
        while(n){
            sum+=(n%10)*(n%10);
            n=n/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=next(slow);
        while(slow!=1&&fast!=1){
            if(fast==slow){
                return false;
            }
            slow=next(slow);
            fast=next(next(fast));
        }
        return true;
    }
};