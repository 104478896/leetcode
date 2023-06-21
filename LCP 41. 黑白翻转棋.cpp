/*在 n*m 大小的棋盘中，有黑白两种棋子，黑棋记作字母 "X", 白棋记作字母 "O"，空余位置记作 "."。
当落下的棋子与其他相同颜色的棋子在行、列或对角线完全包围（中间不存在空白位置）另一种颜色的棋子，
则可以翻转这些棋子的颜色。

「力扣挑战赛」黑白翻转棋项目中，将提供给选手一个未形成可翻转棋子的棋盘残局，其状态记作 chessboard。
若下一步可放置一枚黑棋，请问选手最多能翻转多少枚白棋。

注意：

    若翻转白棋成黑棋后，棋盘上仍存在可以翻转的白棋，将可以 继续 翻转白棋
    输入数据保证初始棋盘状态无可以翻转的棋子且存在空余位置

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/fHi6rV
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    //全局初始化变量，设置方向的遍历，避免过多的if条件
    const int directions[8][2]={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};

    //判断该方向是否由符合条件的白棋
    bool jus(vector<string>& chessboard,int x,int y,int dx,int dy){
        x+=dx;//沿固定方向移动
        y+=dy;
        int row=chessboard.size();//棋盘行
        int col=chessboard[0].size();//棋盘列
        while(x>=0 && x<row && y>=0 && y<col){//棋位置位于棋盘
            if(chessboard[x][y]=='X'){//当遇到黑棋时，表示与起点的黑棋之间均符合条件，返回true
                return true;
            }else if(chessboard[x][y]=='.'){//当遇到空位置时，表示与起点黑棋之间有空位置，
                //不符合条件，返回false
                return false;
            }
            //沿该方向移动
            x+=dx;
            y+=dy;

        }
        return false;
    }
    //广度优先遍历，遍历下棋位置周围所有方向上可以改变的白棋
    int bfs(vector<string> chessboard,int x,int y){
        int cont=0;
        queue<pair<int,int>>q;//队列存储对应方向上所有的黑棋，包含白棋转变的黑棋
        q.emplace(x,y);
        chessboard[x][y]='X';//将下棋位置置为黑棋
        
        
        while(!q.empty()){//队列不为空
            pair<int,int> t=q.front();
            q.pop();//弹出队首元素
            for(int i=0;i<8;++i){//遍历八个方向
                //判断该方向上是否存在符合条件的情况
                if(jus(chessboard,t.first,t.second,directions[i][0],directions[i][1])){
                    //沿该方向移动，找到符合条件的棋数
                    int tx=t.first+directions[i][0];
                    int ty=t.second+directions[i][1];
                    while(chessboard[tx][ty]!='X'){//进入if内，表示黑棋之间不是黑棋就是白棋
                        q.emplace(tx,ty);//将棋放入队列
                        chessboard[tx][ty]='X';//以遍历的白棋置为黑棋
                        tx+=directions[i][0];//移动
                        ty+=directions[i][1];
                        ++cont;
                    }
                }
            }
        }
        
        return cont;
    }


    int flipChess(vector<string>& chessboard) {
        int row=chessboard.size();
        int col=chessboard[0].size();
        int res=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){//遍历棋盘，进行广度优先遍历
                res=max(res,bfs(chessboard,i,j));
            }
        }
        return res;
    }
};