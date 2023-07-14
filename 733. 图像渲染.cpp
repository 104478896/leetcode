/*有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。

你也被给予三个整数 sr ,  sc 和 newColor 。你应该从像素 image[sr][sc] 开始对图像进行 上色填充 。

为了完成 上色工作 ，从初始像素开始，记录初始坐标的 上下左右四个方向上 像素值与初始坐标相同的相连像素点，接着再记录这四个方向上符合条件的像素点与他们对应 四个方向上 像素值与初始坐标相同的相连像素点，……，重复该过程。将所有有记录的像素点的颜色值改为 newColor 。

最后返回 经过上色渲染后的图像 。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/flood-fill
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    void dfs(vector<vector<int>>& image,int x,int y,int begColor,int color){
        if(x<0||y<0||x>image.size()-1||y>image[x].size()-1||image[x][y]!=begColor){
            return;
        }

        image[x][y]=color;

        dfs(image,x-1,y,begColor,color);
        dfs(image,x,y-1,begColor,color);
        dfs(image,x+1,y,begColor,color);
        dfs(image,x,y+1,begColor,color);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]!=color){
            dfs(image,sr,sc,image[sr][sc],color);
        }
        
        return image;
    }
};