/*现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1。给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi] ，表示在选修课程 ai 前 必须 先选修 bi 。

例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1] 。
返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序，你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组 。

 */
 class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edges(numCourses);
        vector<int>inedge(numCourses);
        
        for(auto num:prerequisites){
            edges[num[1]].push_back(num[0]);
            inedge[num[0]]++;
        }
        queue<int>que;
        vector<int>ans;
        for(int i=0;i<numCourses;++i){
            if(inedge[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int nex=que.front();
            ans.push_back(nex);
            que.pop();
            for(auto num:edges[nex]){
                inedge[num]--;
                if(inedge[num]==0){
                    que.push(num);
                }
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};