/*给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>cnt;
        for(auto num:nums){
            cnt.insert(num);

        }
        int ans=0;
        for(auto num:cnt){
            if(!cnt.count(num-1)){//如果num-1在哈希表中，代表当前数不是连续数列的起始位置
            //进行下一次查找
            //如果不在，以当前数为起始位置开始寻找连续数列
                int temp=1;
                int curNum=num;
                while(cnt.count(curNum+1)){
                    temp++;
                    curNum++;
                }
                ans=max(ans,temp);
            }

        }
        return ans;
    }
};