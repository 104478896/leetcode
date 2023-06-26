/*给你一个整数 num ，请你返回三个连续的整数，它们的 和 为 num 。如果 num 无法被表示成三个连续整数的和，请你返回一个 空 数组。*/
class Solution {
public:
    //符合条件的整数只有能被三整除的数，三个整数分别为，除以三后加一和减一以及除三所得的数
    vector<long long> sumOfThree(long long num) {
        vector<long long>ans;
        if(num%3==0){
            long long temp=num/3;
            ans.push_back(temp-1);
            ans.push_back(temp);
            ans.push_back(temp+1);
            
        }
        return ans;
    }
};