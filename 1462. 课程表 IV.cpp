/*你总共需要上 numCourses 门课，课程编号依次为 0 到 numCourses-1 。你会得到一个数组 prerequisite ，其中 prerequisites[i] = [ai, bi] 表示如果你想选 bi 课程，你 必须 先选 ai 课程。

有的课会有直接的先修课程，比如如果想上课程 1 ，你必须先上课程 0 ，那么会以 [0,1] 数对的形式给出先修课程数对。
先决条件也可以是 间接 的。如果课程 a 是课程 b 的先决条件，课程 b 是课程 c 的先决条件，那么课程 a 就是课程 c 的先决条件。

你也得到一个数组 queries ，其中 queries[j] = [uj, vj]。对于第 j 个查询，您应该回答课程 uj 是否是课程 vj 的先决条件。

返回一个布尔数组 answer ，其中 answer[j] 是第 j 个查询的答案。*/
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
      vector<vector<bool>>isPre(numCourses,vector<bool>(numCourses,false));//统计是否为直接或间接先决条件
      vector<int>inedge(numCourses);//统计各个课程的入度即先决条件
      vector<vector<int>>edges(numCourses);//统计出度
      for(auto num:prerequisites){
        inedge[num[1]]++;
        edges[num[0]].push_back(num[1]);
      }
      queue<int>que;
      for(int i=0;i<numCourses;++i){
        if(inedge[i]==0){
          que.push(i);
        }
      }
      while(!que.empty()){
        int cur=que.front();//获取当前队列头，访问当前的出度
        que.pop();
        for(auto edge:edges[cur]){
          isPre[cur][edge]=true;
          for(int i=0;i<numCourses;++i){
            isPre[i][edge]=isPre[i][cur]|isPre[i][edge];
          }
          --inedge[edge];
          if(inedge[edge]==0){
            que.push(edge);
          }
        }
      }
      vector<bool>ans;
      for(auto res:queries){
        ans.push_back(isPre[res[0]][res[1]]);
      }
      return ans;
    }
};