/*给你一个数字数组 arr 。

如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。

如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/can-make-arithmetic-progression-from-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int sub=arr[0]-arr[1];
        int len=arr.size();
        for(int i=1;i<len;++i){
            if(arr[i-1]-arr[i]!=sub){
                return false;
            }
        }
        return true;
    }
};