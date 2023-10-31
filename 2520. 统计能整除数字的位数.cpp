/*给你一个整数 num ，返回 num 中能整除 num 的数位的数目。

如果满足 nums % val == 0 ，则认为整数 val 可以整除 nums 。

 */
 class Solution {
public:
    int countDigits(int num) {
        string str=to_string(num);
        int ans=0;
        for(char ch:str){
            int temp=ch-'0';
            if(num%temp==0){
                ans++;
            }
        }
        return ans;
    }
};