/*给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。

最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。

你可以假设除了整数 0 之外，这个整数不会以零开头。*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len=digits.size();
        for(int i=len-1;i>=0;--i){
            if(digits[i]!=9){
                ++digits[i];
                for(int j=i+1;j<len;++j){
                    digits[j]=0;
                }
                return digits;
            }
        }
        vector<int>ans(len+1);
        ans[0]=1;
        return ans;
    }
};