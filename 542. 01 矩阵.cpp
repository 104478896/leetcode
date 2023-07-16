/*给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/01-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        vector<vector<int>>dist(row,vector<int>(col,INT_MAX));
        
        queue<pair<int,int>>que;
        for(int i=0;i<row;++i){
            //将所有的零初始位置放入队列
            //将dist的矩阵中将原矩阵中的零位置置零
            for(int j=0;j<col;++j){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    que.push({i,j});
                }
            }
        }
        int dirs[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        while(!que.empty()){//当队列不为空
            int r=que.front().first;//取出队列首部元素
            int c=que.front().second;
            que.pop();//弹出首部元素
            for(int i=0;i<4;++i){//向定点周围遍历
                int update_r=r+dirs[i][0];//更新后的坐标位置
                int update_c=c+dirs[i][1];

                if(update_r>=0&&update_c>=0&&update_r<row&&update_c<col){
                    //新坐标没有超出矩阵范围
                    //新坐标的距离零的距离为起点坐标的值加一
                    //将新坐标的值与起点坐标的值加一的值进行比较取较小值
                    //将新坐标的(x,y)放入队列
                    if(dist[update_r][update_c]-1>dist[r][c]){
                        dist[update_r][update_c]=dist[r][c]+1;
                        que.push({update_r,update_c});
                    }
                }
            }
        }


        return dist;
    }
};