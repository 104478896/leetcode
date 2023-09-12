/*你这个学期必须选修 numCourses 门课程，记为 0 到 numCourses - 1 。

在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

例如，先修课程对 [0, 1] 表示：想要学习课程 0 ，你需要先完成课程 1 。
请你判断是否可能完成所有课程的学习？如果可以，返回 true ；否则，返回 false 。*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>edges;
        edges.resize(numCourses);
        vector<int>inedge(numCourses);//入度统计
        for(auto num:prerequisites){
            edges[num[1]].push_back(num[0]);
            inedge[num[0]]++;
        }
        queue<int>que;
        for(int i=0;i<numCourses;++i){
            if(inedge[i]==0){
                que.push(i);
            }
        }
        int visited=0;
        while(!que.empty()){
            ++visited;
            int nex=que.front();
            que.pop();
            //访问当前边的出度，同时将对应出度的入度减一，当归零时(即已完成对应课程的前置课程)放入队列
            for(auto num:edges[nex]){
                inedge[num]--;
                if(inedge[num]==0){
                    que.push(num);
                }
            }
        }
        return visited==numCourses;
    }
};