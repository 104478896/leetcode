/*给你一个整数 n，请你帮忙计算并返回该整数「各位数字之积」与「各位数字之和」的差。*/
// class Solution {
// public:
//     int subtractProductAndSum(int n) {
//         int sum=0;
//         int mul=1;
//         while(n){
//             sum+=n%10;
//             mul*=n%10;
//             n/=10;
//         }
//         int ans=mul-sum;
//         return ans;
//     }
// };
class Solution {
public:
    int subtractProductAndSum(int n) {
        string word=to_string(n);
        int len=word.size();
        int mul=word[0]-'0';
        int add=word[0]-'0';
        for(int i=1;i<len;++i){
            mul*=word[i]-'0';
            add+=word[i]-'0';
        }
        int res=mul-add;
        return res;
    }
};