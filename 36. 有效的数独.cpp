/*请你判断一个 9 x 9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
 

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。
空白格用 '.' 表示。
 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/valid-sudoku
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int col[9][9]={0};
        int box[3][3][9]={0};
        for(int i=0;i<9;++i){
            for(int j=0;j<9;++j){
                if(board[i][j]!='.'){
                    int index=board[i][j]-'0'-1;
                    if(row[i][index]){
                        return false;
                    }
                    if(col[j][index]){
                        return false;
                    }
                    if(box[i/3][j/3][index]){
                        return false;
                    }
                    row[i][index]=1;
                    col[j][index]=1;
                    box[i/3][j/3][index]=1;
                }
            }
        }
        return true;
    }
};