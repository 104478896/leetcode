/*给你两个整数 n 和 k 。

对于一个由 不同 正整数组成的数组，如果其中不存在任何求和等于 k 的不同元素对，则称其为 k-avoiding 数组。

返回长度为 n 的 k-avoiding 数组的可能的最小总和。*/


class Solution {
public:
    int minimumSum(int n, int k) {
        //暴力
        // int ans=0;
        // int cnt=1;
        // vector<int>temp(n);
        // for(int i=0;i<n;++i){
        //     temp[i]=cnt;
        //     for(int j=0;j<i;++j){
        //         if(temp[i]+temp[j]==k){
        //             temp[i]=0;
        //             i--;
        //             break;
        //         }
        //     }
        //     cnt++;
        // }
        // ans=accumulate(temp.begin(),temp.end(),0);
        // return ans;


        //等差数列
        //当选择数字小于k时，只能从以k/2两侧选择其一，为保证结果较小，选择小于k/2的数字
        //当n比k/2大时，需要额外选择数字，保证数组中没有数对之和等于k，额外的数字需要从大于等于k中选择
        
        // int m=min(k/2,n);
        // return (m+1)*m/2+(k+k+n-m-1)*(n-m)/2;
    }
};