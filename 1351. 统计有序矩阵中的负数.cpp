/*给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 请你统计并返回 grid 中 负数 的数目。*/
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        // //暴力
        // int row=grid.size();
        // int col=grid[0].size();
        // int ans=0;
        // for(int i=0;i<row;++i){
        //     for(int j=0;j<col;++j){
        //         if(grid[i][j]<0){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;


        //二分查找
        int row=grid.size();
        int ans=0;
        for(int i=0;i<row;++i){
            int left=0;
            int right=grid[i].size()-1;
            int mid;
            while(left<=right){
                mid=left+(right-left)/2;
                if(grid[i][mid]>=0){
                    left=mid+1;
                }else{
                    right=mid-1;
                }
            }

            ans+=grid[i].size()-left;
        }
        return ans;
    }
};