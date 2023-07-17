/*给你一个正方形矩阵 mat，请你返回矩阵对角线元素的和。

请你返回在矩阵主对角线上的元素和副对角线上且不在主对角线上元素的和。*/
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        //暴力
        // int len=mat.size();
        // int ans=0;
        // for(int i=0;i<len;++i){
        //     for(int j=0;j<len;++j){
        //         if(i==j||i+j==len-1){
        //             ans+=mat[i][j];
        //         }
        //     }
        // }
        

        //逐行取数，读取
        int len=mat.size();
        int ans=0;
        for(int i=0;i<len;++i){
            ans+=mat[i][i]+mat[i][len-1-i];

        }
        if(len%2==1){
            ans-=mat[len/2][len/2];
        }
        
        return ans;
    }
};