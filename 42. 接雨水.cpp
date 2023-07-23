/*给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。*/
class Solution {
public:
    int trap(vector<int>& height) {
        int len=height.size();
        if(len==0){
            return 0;
        }
        vector<int>leftMax(len);
        vector<int>rightMax(len);
        leftMax[0]=height[0];
        rightMax[len-1]=height[len-1];
        for(int i=1;i<len;++i){
            leftMax[i]=max(height[i],leftMax[i-1]);
        }

        for(int i=len-2;i>=0;--i){
            
            rightMax[i]=max(height[i],rightMax[i+1]);
        }
        int ans=0;
        for(int i=0;i<len;++i){
            ans+=min(leftMax[i],rightMax[i])-height[i];
        }
        return ans;
    }
};