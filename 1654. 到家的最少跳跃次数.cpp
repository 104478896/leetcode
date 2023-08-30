/*有一只跳蚤的家在数轴上的位置 x 处。请你帮助它从位置 0 出发，到达它的家。

跳蚤跳跃的规则如下：

它可以 往前 跳恰好 a 个位置（即往右跳）。
它可以 往后 跳恰好 b 个位置（即往左跳）。
它不能 连续 往后跳 2 次。
它不能跳到任何 forbidden 数组中的位置。
跳蚤可以往前跳 超过 它的家的位置，但是它 不能跳到负整数 的位置。

给你一个整数数组 forbidden ，其中 forbidden[i] 是跳蚤不能跳到的位置，同时给你整数 a， b 和 x ，请你返回跳蚤到家的最少跳跃次数。如果没有恰好到达 x 的可行方案，请你返回 -1 。*/
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        //最远距离 bound=max(MAXF+a+b,x+b);
        int MAXF=*max_element(forbidden.begin(),forbidden.end());//最大的禁止点
        int bound=max(MAXF+a+b,x+b);//定义上边界
        vector<int>ban(bound+1,0);
        for(auto f:forbidden){
            ban[f]=1;//标记禁止点
        }
        int dist[bound+1][2];
        memset(dist,0x3f,sizeof(dist));
        dist[0][0]=0;
        queue<pair<int,int>>que;
        que.push({0,0});
        while(!que.empty()){
            auto [pos,op] = que.front();
            que.pop();
            //如果当前位置等于x,代表已经到达终点
            if(pos==x){
                return dist[pos][op];
            }
            //上一步操作是前进，同时向后退大于等零，后退后的位置不是禁止点
            if(op==0&&pos-b>=0&&!ban[pos-b]&&dist[pos][op]+1<dist[pos-b][1]){
                dist[pos-b][1]=dist[pos][op]+1;
                que.push({pos-b,1});
            }
            if(pos+a<=bound&&!ban[pos+a]&&dist[pos][op]+1<dist[pos+a][0]){
                dist[pos+a][0]=dist[pos][op]+1;
                que.push({pos+a,0});
            }
        }
        return -1;
    }
};