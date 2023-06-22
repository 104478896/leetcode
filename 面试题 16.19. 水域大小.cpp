/*你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。
若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。
编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。

示例：

输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
提示：

0 < len(land) <= 1000
0 < len(land[i]) <= 1000

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/pond-sizes-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    const int dirs[8][2]={{-1,-1},{-1,1},{1,-1},{1,1},{-1,0},{1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& land,int x,int y){
        if(x<0||y<0||x>=land.size()||y>=land[0].size()||land[x][y]!=0){
            return 0;
        }
        int count=1;
        land[x][y]=-1;
        for(int i=0;i<8;++i){
            count+=dfs(land,x+dirs[i][0],y+dirs[i][1]);
        }
        return count;

        
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int>ans;
        int row=land.size();
        int col=land[0].size();
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(land[i][j]==0){
                    ans.push_back(dfs(land,i,j));
                }
                
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};