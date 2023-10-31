/*有一棵根节点为 0 的 家族树 ，总共包含 n 个节点，节点编号为 0 到 n - 1 。给你一个下标从 0 开始的整数数组 parents ，其中 parents[i] 是节点 i 的父节点。由于节点 0 是 根 ，所以 parents[0] == -1 。

总共有 105 个基因值，每个基因值都用 闭区间 [1, 105] 中的一个整数表示。给你一个下标从 0 开始的整数数组 nums ，其中 nums[i] 是节点 i 的基因值，且基因值 互不相同 。

请你返回一个数组 ans ，长度为 n ，其中 ans[i] 是以节点 i 为根的子树内 缺失 的 最小 基因值。

节点 x 为根的 子树 包含节点 x 和它所有的 后代 节点。

 */
 class Solution {
public:
    void dfs(int x,vector<int>&nums,set<int>&visit,vector<vector<int>>&gree){
        visit.insert(nums[x]);//将当前基因值存入哈希表进行标记
        for(int son:gree[x]){//遍历节点x的子节点
            if(!visit.count(nums[son])){//如果节点没有进行过标记，可以进行深度搜索
                dfs(son,nums,visit,gree);
            }
        }
    }
    vector<int> smallestMissingValueSubtree(vector<int>& parents, vector<int>& nums) {
        int len=parents.size();
        vector<int>ans(len,1);
        auto it=find(nums.begin(),nums.end(),1);//查找基因值1
        if(it==nums.end()){//如果没有找到基因值1，那么对应的所有节点的最小基因值均为1
            return ans;
        }

        vector<vector<int>>gree(len);
        for(int i=1;i<len;++i){//将每个节点存入对应的父节点的容器中
            gree[parents[i]].push_back(i);
        }

        set<int>visit;
        int mex=2;//进行到当前步骤以为着缺失基因的可能值最小为2
        int node=it-nums.begin();//从基因值为1的位置开始进行遍历
        while(node>=0){
            dfs(node,nums,visit,gree);
            while(visit.count(mex)){//node子树中包含这个基因值，将基因值的最小值加1
                mex++;
            }
            ans[node]=mex;//缺失的基因值
            node=parents[node];//往上走,将深搜节点更改为node的父节点

        }
        return ans;

    }
};