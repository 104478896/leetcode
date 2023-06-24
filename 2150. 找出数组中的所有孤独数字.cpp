/*给你一个整数数组 nums 。如果数字 x 在数组中仅出现 一次 ，且没有 相邻 数字（即，x + 1 和 x - 1）出现在数组中，则认为数字 x 是 孤独数字 。

返回 nums 中的 所有 孤独数字。你可以按 任何顺序 返回答案

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-all-lonely-numbers-in-the-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {

        map<int,int>count;
        for(auto num:nums){
            count[num]++;
        }
        vector<int>ans;
        for(auto [key,val]:count){
            if(val==1&&count.find(key-1)==count.end()&&count.find(key+1)==count.end()){
                ans.push_back(key);
            }
        }
        return ans;
    }
};