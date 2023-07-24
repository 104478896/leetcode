/*给你一个正整数 n ，返回 2 和 n 的最小公倍数（正整数）。*/
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n%2==0){
            return n;
        }else{
            return 2*n;
        }
    }
};