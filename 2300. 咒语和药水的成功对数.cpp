/*给你两个正整数数组 spells 和 potions ，长度分别为 n 和 m ，其中 spells[i] 表示第 i 个咒语的能量强度，potions[j] 表示第 j 瓶药水的能量强度。

同时给你一个整数 success 。一个咒语和药水的能量强度 相乘 如果 大于等于 success ，那么它们视为一对 成功 的组合。

请你返回一个长度为 n 的整数数组 pairs，其中 pairs[i] 是能跟第 i 个咒语成功组合的 药水 数目。*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        int len=spells.size();
        for(int i=0;i<len;++i){
            int left=0;
            int right=potions.size()-1;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(potions[mid]<=(success-1)/spells[i]){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            ans.push_back(potions.size()-left);
        }
        return ans;
    }
};