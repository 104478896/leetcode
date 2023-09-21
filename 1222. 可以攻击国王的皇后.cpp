/*在一个 8x8 的棋盘上，放置着若干「黑皇后」和一个「白国王」。

给定一个由整数坐标组成的数组 queens ，表示黑皇后的位置；以及一对坐标 king ，表示白国王的位置，返回所有可以攻击国王的皇后的坐标(任意顺序)。*/
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        set<pair<int,int>>cnt;
        for(auto arr:queens){
            cnt.insert({arr[0],arr[1]});
        }
        vector<vector<int>>ans;
        for(int dx=-1;dx<=1;++dx){
            for(int dy=-1;dy<=1;++dy){
                if(dx==0&&dy==0){
                    continue;
                }
                int tx=king[0]+dx;
                int ty=king[1]+dy;
                while(tx>=0&&ty>=0&&tx<8&&ty<8){
                    if(cnt.count({tx,ty})){
                        ans.push_back({tx,ty});
                        break;
                    }
                    tx+=dx;
                    ty+=dy;
                }
            }

        }
        return ans;
    }
};