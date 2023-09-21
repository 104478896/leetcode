/*给你一个 n 个节点的无向无根树，节点编号从 0 到 n - 1 。给你整数 n 和一个长度为 n - 1 的二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示树中节点 ai 和 bi 之间有一条边。再给你一个长度为 n 的数组 coins ，其中 coins[i] 可能为 0 也可能为 1 ，1 表示节点 i 处有一个金币。

一开始，你需要选择树中任意一个节点出发。你可以执行下述操作任意次：

收集距离当前节点距离为 2 以内的所有金币，或者
移动到树中一个相邻节点。
你需要收集树中所有的金币，并且回到出发节点，请你返回最少经过的边数。

如果你多次经过一条边，每一次经过都会给答案加一。*/
class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int len=coins.size();//节点数
        vector<vector<int>>gree(len);//构建树
        vector<int>edgeCnt(len);//统计每个节点的度
        for(auto &e:edges){
            int x=e[0];
            int y=e[1];
            gree[x].push_back(y);
            gree[y].push_back(x);//建树
            edgeCnt[x]++;
            edgeCnt[y]++;//节点度统计
        }
        int left_edges=len-1;//剩余边数
        //拓扑排序，去点没有金币的子树
        vector<int>que;
        for(int i=0;i<len;++i){//将度为0的节点放入队列
            if(edgeCnt[i]==1&&coins[i]==0){//没有金币的叶子节点
                que.push_back(i);
            }
        }
        while(!que.empty()){
            left_edges--;
            int temp=que.back();
            que.pop_back();
            for(int g:gree[temp]){
                if(--edgeCnt[g]==1&&coins[g]==0){//当前节点为叶子节点，同时没有金币，放入队列
                    que.push_back(g);
                }
            }
        }

        //再次进行拓扑排序
        for(int i=0;i<len;++i){
            if(edgeCnt[i]==1&&coins[i]){//将叶子节点存有金币的放入队列
                que.push_back(i);
            }
        }
        left_edges-=que.size();//删除叶子节点(即各个叶子节点到其父节点的边)
        for(int x:que){//遍历所有叶子
            for(int y:gree[x]){
                if(--edgeCnt[y]==1){//当叶子节点的父节点的度为1，则父节点变为叶子节点
                    left_edges--;//删除父节点(即当前叶子节点到父节点的边)
                }
            }
        }
        return max(left_edges*2,0);
    }
};