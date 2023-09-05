/*给你一个无向图，整数 n 表示图中节点的数目，edges 数组表示图中的边，其中 edges[i] = [ui, vi] ，表示 ui 和 vi 之间有一条无向边。

一个 连通三元组 指的是 三个 节点组成的集合且这三个点之间 两两 有边。

连通三元组的度数 是所有满足此条件的边的数目：一个顶点在这个三元组内，而另一个顶点不在这个三元组内。

请你返回所有连通三元组中度数的 最小值 ，如果图中没有连通三元组，那么返回 -1 。*/
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>cnt(n,vector<int>(n));//存储每条边的联通情况
        vector<int>degree(n);
        for(auto edge:edges){
            int x=edge[0]-1;//从零开始访问,边是从1开始计数
            int y=edge[1]-1;
            cnt[x][y]=cnt[y][x]=1;
            ++degree[x];
            ++degree[y];
        }
        int ans=INT_MAX;
       // 对于一个连通三元组 (i,j,k)(i, j, k)(i,j,k)，
       //它的度数即为：degree(i)+degree(j)+degree(k)−6
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(cnt[i][j]==1){
                    for(int k=j+1;k<n;++k){
                        if(cnt[j][k]==1&&cnt[i][k]==1){
                            ans=min(ans,degree[i]+degree[j]+degree[k]-6);
                        }
                    }
                }
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};