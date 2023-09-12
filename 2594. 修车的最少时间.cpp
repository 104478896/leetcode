/*给你一个整数数组 ranks ，表示一些机械工的 能力值 。ranksi 是第 i 位机械工的能力值。能力值为 r 的机械工可以在 r * n2 分钟内修好 n 辆车。

同时给你一个整数 cars ，表示总共需要修理的汽车数目。

请你返回修理所有汽车 最少 需要多少时间。

注意：所有机械工可以同时修理汽车。*/
class Solution {
public:
    bool check(vector<int>&ranks,long long mid,int cars){
        long long cnt=0;
        for(auto x:ranks){
            cnt+=sqrt(mid/x);
        }
        return cnt>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left=0;
        long long right=(long long)ranks[0]*cars*cars;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(check(ranks,mid,cars)){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};