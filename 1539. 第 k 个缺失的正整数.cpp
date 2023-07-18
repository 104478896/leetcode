/*给你一个 严格升序排列 的正整数数组 arr 和一个整数 k 。

请你找到这个数组里第 k 个缺失的正整数。*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k){
            return k;
        }
        int left=0;
        int right=arr.size()-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(arr[mid]-mid-1<k){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        
        //left位于数组右侧，查找数组右侧的缺失数差几个，arr[left-1](数组最后一个数)
        //arr[left-1]-(left-1+1) 截至最后缺失整数的数量   
        if(left==arr.size()&&arr[left-1]-left<k){//k代表缺失的第几个整数，
        //缺失位置位于数组之后，代表数组长度加上缺失数的数量就是缺失数
            return k+arr.size();
        }
        
        //k-(arr[left-1]-(left-1+1))+arr[left-1]  ==> k+left
        return k+left;
    }
};