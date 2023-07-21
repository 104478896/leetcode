/*给你一个整数数组 arr 。请你将数组中的元素按照其二进制表示中数字 1 的数目升序排序。

如果存在多个数字二进制中 1 的数目相同，则必须将它们按照数值大小升序排列。

请你返回排序后的数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int total(int num){
        int count=0;
        while(num){
            count+=num&1;
            num=num/2;
        }
        return count;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int len=arr.size();
        vector<vector<int>>cnt(len,vector<int>(2));
        for(int i=0;i<len;++i){
            cnt[i][0]=arr[i];
            cnt[i][1]=total(arr[i]);
            // cout<<cnt[i][0]<<cnt[i][1]<<endl;
        }
        sort(cnt.begin(),cnt.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
            });
        vector<int>ans;
        for(int i=0;i<len;++i){
            ans.push_back(cnt[i][0]);
        }
        return ans;

    }
};