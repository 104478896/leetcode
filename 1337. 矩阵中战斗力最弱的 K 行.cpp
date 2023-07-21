/*给你一个大小为 m * n 的矩阵 mat，矩阵由若干军人和平民组成，分别用 1 和 0 表示。

请你返回矩阵中战斗力最弱的 k 行的索引，按从最弱到最强排序。

如果第 i 行的军人数量少于第 j 行，或者两行军人数量相同但 i 小于 j，那么我们认为第 i 行的战斗力比第 j 行弱。

军人 总是 排在一行中的靠前位置，也就是说 1 总是出现在 0 之前。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/the-k-weakest-rows-in-a-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int len=mat.size();
        vector<vector<int>>ans;
        int mid;
        for(int i=0;i<len;++i){
            int left=0;
            int right=mat[i].size()-1;
            while(left<=right){
                mid=(right+left)/2;
                if(mat[i][mid]==0){
                    right=mid-1;
                }else{
                    left=mid+1;
                }
            }
            ans.push_back({i,left});

            
        }


        sort(ans.begin(),ans.end(),[](const vector<int>&a,const vector<int>&b){
            if(a[1]==b[1]){
                return a[0]<b[0];
            }
            return a[1]<b[1];
        });

        vector<int>res;
        for(int i=0;i<k;++i){
            
            res.push_back(ans[i][0]);
        }
        return res;
    }
};