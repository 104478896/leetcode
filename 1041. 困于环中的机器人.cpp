/*在无限的平面上，机器人最初位于 (0, 0) 处，面朝北方。注意:

北方向 是y轴的正方向。
南方向 是y轴的负方向。
东方向 是x轴的正方向。
西方向 是x轴的负方向。
机器人可以接受下列三条指令之一：

"G"：直走 1 个单位
"L"：左转 90 度
"R"：右转 90 度
机器人按顺序执行指令 instructions，并一直重复它们。

只有在平面中存在环使得机器人永远无法离开时，返回 true。否则，返回 false。*/
class Solution {
public:
    bool isRobotBounded(string instructions) {
        vector<vector<int>>dict={{0,1},{1,0},{0,-1},{-1,0}};//上，右，下，左
        int dictIndex=0;
        int x=0;
        int y=0;
        for(auto instruction:instructions){
            if(instruction=='G'){
                x+=dict[dictIndex][0];
                y+=dict[dictIndex][1];
            }else if(instruction=='L'){
                dictIndex+=3;
                dictIndex%=4;
            }else{
                dictIndex++;
                dictIndex%=4;
            }
        }
        if(x==0&&y==0){
            return true;
        }
        return dictIndex!=0;
    }
};