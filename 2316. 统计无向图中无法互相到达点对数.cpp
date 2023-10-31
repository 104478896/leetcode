/*给你一个整数 n ，表示一张 无向图 中有 n 个节点，编号为 0 到 n - 1 。同时给你一个二维整数数组 edges ，其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边。

请你返回 无法互相到达 的不同 点对数目 。*/
class Solution {
public:
    int dfs(int i,vector<vector<int>>&edgeCnt,vector<bool>&visit){
        if(visit[i]==true){
            return 0;
        }
        visit[i]=true;
        int res=1;
        for(auto e:edgeCnt[i]){
            res+=dfs(e,edgeCnt,visit);
        }
        return res;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>>edgeCnt(n);//统计边
        for(auto e:edges){
            edgeCnt[e[0]].push_back(e[1]);
            edgeCnt[e[1]].push_back(e[0]);
        }
        long long ans=0;
        long long total=0;
        vector<bool> visit(n);
        for(int i=0;i<n;++i){
            long long cnt=dfs(i,edgeCnt,visit);
            ans+=cnt*total;
            total+=cnt;
        }   
        return ans;
    }
};