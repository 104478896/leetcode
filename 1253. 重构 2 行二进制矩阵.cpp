/*给你一个 2 行 n 列的二进制数组：

矩阵是一个二进制矩阵，这意味着矩阵中的每个元素不是 0 就是 1。
第 0 行的元素之和为 upper。
第 1 行的元素之和为 lower。
第 i 列（从 0 开始编号）的元素之和为 colsum[i]，colsum 是一个长度为 n 的整数数组。
你需要利用 upper，lower 和 colsum 来重构这个矩阵，并以二维整数数组的形式返回它。

如果有多个不同的答案，那么任意一个都可以通过本题。

如果不存在符合要求的答案，就请返回一个空的二维数组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        //两行n列，upper第一行，lower第二行，colsum每一列
        int len=colsum.size();//列数
        vector<vector<int>>ans;
        // if(len<upper+lower){
        //     return ans;
        // }
        vector<int>up;
        vector<int>low;
        for(int i=0;i<len;++i){
            if(colsum[i]==2){
                upper--;
                lower--;
                up.push_back(1);
                low.push_back(1);
            }else if(colsum[i]==1){
                if(upper>lower){
                    upper--;
                    up.push_back(1);
                    low.push_back(0);
                }else{
                    lower--;
                    up.push_back(0);
                    low.push_back(1);
                }
            }else{
                up.push_back(0);
                low.push_back(0);
                continue;
            }
        }
        if(upper||lower){
            return ans;
        }
        ans.push_back(up);
        ans.push_back(low);
        return ans;
    }
};