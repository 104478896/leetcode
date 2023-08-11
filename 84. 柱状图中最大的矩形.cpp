/*给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>stk;
        int len=heights.size();
        int ans=0;
        for(int i=0;i<len;++i){
            while(!stk.empty()&&heights[stk.top()]>heights[i]){
                int height=heights[stk.top()];
                stk.pop();
                while(!stk.empty()&&heights[stk.top()]==height){
                    stk.pop();
                }
                int width=stk.empty()?i:i-stk.top()-1;
                ans=max(ans,width*height);
            }
            stk.push(i);
        }

        while(!stk.empty()){
            int height=heights[stk.top()];
            stk.pop();
            while(!stk.empty()&&heights[stk.top()]==height){
                stk.pop();
            }
            int width=stk.empty()?len:len-stk.top()-1;
            ans=max(ans,width*height);
        }
        return ans;
    }
};