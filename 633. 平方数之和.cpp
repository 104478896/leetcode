/*给定一个非负整数 c ，你要判断是否存在两个整数 a 和 b，使得 a2 + b2 = c 。*/
class Solution {
public:
    bool judgeSquareSum(int c) {   
        int len=(int)sqrt(c);
        for(int i=0;i<=len;++i){
            long left=i;
            long right=(int)sqrt(c);
            long mid;
            while(left<=right){
                mid=left+(right-left)/2;
                if((mid*mid+i*i)<c){
                    left=mid+1;
                }else if((mid*mid+i*i)>c){
                    right=mid-1;
                }else{
                    return true;
                }
            }
        }
        return false;
        
    }
};