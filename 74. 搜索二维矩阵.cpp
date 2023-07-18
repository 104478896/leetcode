/*给你一个满足下述两条属性的 m x n 整数矩阵：

每行中的整数从左到右按非递减顺序排列。
每行的第一个整数大于前一行的最后一个整数。
给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/search-a-2d-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // //暴力
        // int row=matrix.size();
        // int col=matrix[0].size();
        // for(int i=0;i<row;++i){
        //     for(int j=0;j<col;++j){
        //         if(matrix[i][j]==target){
        //             return true;
        //         }
        //     }
        // }
        // return false;


        //二分查找
        int row=matrix.size();
        int col=matrix[0].size();
        int len=row*col;
        int left=0;
        int right=len-1;
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(matrix[mid/col][mid%col]==target){
                return true;
            }else if(matrix[mid/col][mid%col]<target){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return false;
    }
};