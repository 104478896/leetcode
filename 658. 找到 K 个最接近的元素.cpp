/*给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int len=arr.size();
        int left=0;
        int right=len-1;
        //找到第一个大于或等于x的值的位置，从该位置进行比较
        while(left<=right){
            int mid=left+(right-left)/2;
            if(arr[mid]<x){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        right=left;
        left=right-1;
        while(k--){
            if(left<0){
                right++;
            }else if(right>=len){
                left--;
            }else if(x-arr[left]<=arr[right]-x){
                left--;
            }else{
                right++;
            }
        }
        return vector<int>(arr.begin()+left+1,arr.begin()+right);
    }
};