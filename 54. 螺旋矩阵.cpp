/*给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int up=0;//上边界
        int down=matrix.size()-1;//下边界
        int left=0;//左边界
        int right=matrix[0].size()-1;//右边界
        
        while(true){
            for(int i=left;i<=right;++i){//从左边界到右边界
                ans.push_back(matrix[left][i]);
            }
            if(++up>down){
                break;
            }
            for(int i=up;i<=down;++i){//从上边界到下边界
                ans.push_back(matrix[i][right]);
            }
            if(--right<left){
                break;
            }
            for(int i=right;i>=left;--i){//从右边界到左边界
                ans.push_back(matrix[down][i]);
            }
            if(--down<up){
                break;
            }
            for(int i=down;i>=up;--i){//从下边界向上边界
                ans.push_back(matrix[i][left]);
            }
            if(++left>right){
                break;
            }

        }
        return ans;
    }
};