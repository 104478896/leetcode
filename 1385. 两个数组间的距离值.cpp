/*给你两个整数数组 arr1 ， arr2 和一个整数 d ，请你返回两个数组之间的 距离值 。

「距离值」 定义为符合此距离要求的元素数目：对于元素 arr1[i] ，不存在任何元素 arr2[j] 满足 |arr1[i]-arr2[j]| <= d 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-the-distance-value-between-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        int ans=0;
        int len=arr2.size();
        for(auto num:arr1){
            int left=0;
            int right=len-1;
            int mid;
            bool flag=true;
            while(left<=right){
                mid=(right-left)/2+left;
                if(num-arr2[mid]<(-1)*d){
                    right=mid-1;
                }else if(num-arr2[mid]>d){
                    left=mid+1;
                }else{
                    flag=false;
                    break;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
};