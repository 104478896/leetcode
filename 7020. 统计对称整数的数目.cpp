/*给你两个正整数 low 和 high 。

对于一个由 2 * n 位数字组成的整数 x ，如果其前 n 位数字之和与后 n 位数字之和相等，则认为这个数字是一个对称整数。

返回在 [low, high] 范围内的 对称整数的数目 。*/
class Solution {
public:
    bool helper(string str){
        int left=0;
        int right=str.size()-1;
        int diff=0;
        while(left<right){
            diff+=(str[left++]-'0')-(str[right--]-'0');
        }
        return diff==0;
    }
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;++i){
            string temp=to_string(i);
            if(temp.size()%2==0){
                if(helper(temp)){
                    ans++;
                }
            }
        }
        return ans;
    }
};