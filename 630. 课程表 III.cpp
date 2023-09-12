/*这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。

你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。

返回你最多可以修读的课程数目。*/
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](const vector<int>a,const vector<int>b){
            return a[1]<b[1];//按照last_day升序排列
        });
        priority_queue<int>que;//优先队列，最大堆
        int total=0;//已消耗时间
        for(auto arr:courses){
            int di=arr[0];
            int ei=arr[1];
            if(total+di<=ei){//学习该门课程时间未超过结束时间，直接学习
                total+=di;
                que.push(di);
            }else if(!que.empty()&&que.top()>di){
                //该课程的持续时间小于之前的持续时间最长的课程
                //撤销之前持续时间最长的课程，改为学习当前课程
                //节省的时间可以学习之后的更多课程
                total-=que.top()-di;
                que.pop();
                que.push(di);
            }
        }
        return que.size();
    }
};