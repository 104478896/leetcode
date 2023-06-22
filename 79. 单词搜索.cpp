/*给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。
如果 word 存在于网格中，返回 true ；否则，返回 false 。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，
其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

/*遍历二维字符数组，对于每个字符，如果与单词的第一个字符匹配，就开始进行回溯搜索。
在回溯过程中，我们检查当前位置是否越界、是否已经访问过、以及当前字符是否匹配。
然后，我们标记当前位置为已访问，继续在上、下、左、右四个方向进行回溯。
如果找到了匹配的路径，就返回true，否则继续回溯。
在回溯结束后，将当前位置重新标记为未访问。如果在整个遍历过程中没有找到匹配的路径，就返回false。

作者：i2ecursing-7amportdw8
链接：https://leetcode.cn/problems/word-search/solution/79-dan-ci-sou-suo-by-i2ecursing-7amportd-twcx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/


class Solution {
public:
    bool dfs(vector<vector<char>>& board,int x,int y,string& word,vector<vector<bool>>& visited,int cont){//传参时保证是否访问过的情况时全局可知的
        if(cont==word.size()){//如果已查找到字符长度和字符串长度一样，返回true
            return true;
        }
        //如果访问越界，返回false
        if(x<0||y<0||x>=board.size()||y>=board[0].size()){
            return false;

        }
        //如果已被访问过，返回true
        if(visited[x][y]){
            return false;
        }
        //如果当前的字符与字符串中的不匹配，返回false
        if(word[cont]!=board[x][y]){
            return false;
        }
        //将访问的字符置为已访问
        visited[x][y]=true;
        //向字符的上下左右进行深度遍历，查找结果
        bool res=dfs(board,x,y-1,word,visited,cont+1)||
                 dfs(board,x-1,y,word,visited,cont+1)||
                 dfs(board,x+1,y,word,visited,cont+1)||
                 dfs(board,x,y+1,word,visited,cont+1);
        visited[x][y]=false;
        //返回结果后将字符的访问置为false，
        //以便下次主函数中找到对应首字符后重新访问查找
        return res;

    }

    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        //记录是否被访问过
        vector<vector<bool>> visited(row,vector<bool>(col,false));

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(word[0]==board[i][j]){
                    if(dfs(board,i,j,word,visited,0)){
                        return true;
                    }
                }  
            }
        }
        return false;
    }
};