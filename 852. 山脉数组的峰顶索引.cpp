/*符合下列属性的数组 arr 称为 山脉数组 ：
arr.length >= 3
存在 i（0 < i < arr.length - 1）使得：
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
给你由整数组成的山脉数组 arr ，返回满足 arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] 的下标 i 。

你必须设计并实现时间复杂度为 O(log(n)) 的解决方案。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/peak-index-in-a-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {

        int left=0;
        int right=arr.size()-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]<arr[mid+1]){
                left=mid;
            }else if(arr[mid]<arr[mid-1]){
                right=mid;
            }else{
                return mid;
            }
        }
        return left;
    }
};