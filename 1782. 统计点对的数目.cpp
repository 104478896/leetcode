/*给你一个无向图，无向图由整数 n  ，表示图中节点的数目，和 edges 组成，其中 edges[i] = [ui, vi] 表示 ui 和 vi 之间有一条无向边。同时给你一个代表查询的整数数组 queries 。

第 j 个查询的答案是满足如下条件的点对 (a, b) 的数目：

a < b
cnt 是与 a 或者 b 相连的边的数目，且 cnt 严格大于 queries[j] 。
请你返回一个数组 answers ，其中 answers.length == queries.length 且 answers[j] 是第 j 个查询的答案。

请注意，图中可能会有 重复边 。*/
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        map<int,int>cnt;
        vector<int>degree(n);
        //统计每个点的相连情况
        for(auto edge:edges){
            int x=edge[0]-1;
            int y=edge[1]-1;
            if(x<y){
                swap(x,y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x*n+y]++;
        }

        vector<int>ans;
        vector<int>arr=degree;
        sort(arr.begin(),arr.end());
        for(auto num:queries){
            int total=0;
            for(int i=0;i<n;++i){
                int j=upper_bound(arr.begin()+i+1,arr.end(),num-arr[i])-arr.begin();
                total+=n-j;
            }
            for(auto [key,val]:cnt){
                int x=key/n;
                int y=key%n;
                if(degree[x]+degree[y]>num&&degree[x]+degree[y]-val<=num){
                    total--;
                }
            }
            ans.push_back(total);
        }
        return ans;


    }
};