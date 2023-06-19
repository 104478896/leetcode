/*给你一个整数数组 nums，请你找出并返回能被三整除的元素最大和。*/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // int len=nums.size();
        // vector<int> f={0,INT_MIN,INT_MIN};//f中存储当前分别取余为0，1，2结果的最大值
        // for(auto num:nums){
        //     vector<int> g=f;//g相当于中转，临时存储加上数组中该数值后的余数为0，1，2的情况
        //     for(int i=0;i<3;++i){
        //         //1.当num取余3后余数为0时，为得到对应的余数为0，1，2的值，
        //         //则分别需要加上之前的取余值为0，1，2的值   (0+0,0+1,0+2)->(0,1,2)
        //         //2.当num取余3后余数为1时，为得到对应的余数为0，1，2的值，
        //         //则分别需要加上之前的取余值为2，0，1的值   (1+2,1+0,1+1)->(0,1,2)
        //         //3.当num取余后余数为2时，为得到对应的余数为0，1，2的值，
        //         //则分别需要加上之前的取余值为1，2，0的值   (2+1,2+2,2+0)->(0,1,2)
        //         //f[i]为截至目前对应的余数为0，1，2的最大加和值,加上本次num后，
        //         //分别与对应的余数为0，1，2的值进行比对，取较大值
        //         g[(i+num%3)%3]=max(g[(i+num%3)%3],f[i]+num);
        //     }
        //     f=g;
        // }
        // return f[0];

        vector<int> remainder{0,0,0};
        int a,b,c;
        for(auto num : nums) {
            a = remainder[0] + num;
            b = remainder[1] + num;
            c = remainder[2] + num;
            remainder[a%3] = max(remainder[a%3],a);
            remainder[b%3] = max(remainder[b%3],b);
            remainder[c%3] = max(remainder[c%3],c);
        }
        return remainder[0];


    }
};