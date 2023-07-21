/*给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。

更正式地，检查是否存在两个下标 i 和 j 满足：

i != j
0 <= i, j < arr.length
arr[i] == 2 * arr[j]
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/check-if-n-and-its-double-exist
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int len=arr.size();
        for(int i=0;i<len;++i){
            int left=i+1;
            int right=len-1;
            int mid;
            while(left<=right){
                mid=left+(right-left)/2;
                if(arr[mid]==arr[i]*2){
                    return true;
                }else if(arr[mid]<arr[i]*2){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
            left=0;
            right=i-1;
            while(left<=right){
                mid=left+(right-left)/2;
                if(arr[mid]==arr[i]*2){
                    return true;
                }else if(arr[mid]<arr[i]*2){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }
        }
        return false;
    }
};