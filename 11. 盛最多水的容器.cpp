/*给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

 */
 class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;
        int right=height.size()-1;;
        int ans=0;
        //双指针，左右遍历，取两个高度中较小的，将两个之间的体积与之前最大值进行比较
        //将较小一方的指针向中间移动
        while(left<right){
            int minHeight=min(height[left],height[right]);
            ans=max(ans,minHeight*(right-left));
            if(height[left]<height[right]){
                left++;
            }else{
                right--;
            }
        }
        return ans;
    }
};