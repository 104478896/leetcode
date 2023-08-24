/*给你一个数组 seats 表示一排座位，其中 seats[i] = 1 代表有人坐在第 i 个座位上，seats[i] = 0 代表座位 i 上是空的（下标从 0 开始）。

至少有一个空座位，且至少有一人已经坐在座位上。

亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。

返回他到离他最近的人的最大距离。

 */
 class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans=0;
        int left=0;
        int len=seats.size();
        //当左边缘没有人坐，找到第一个有人的位置
        while(left<len&&seats[left]==0){
            left++;
        }
        ans=max(ans,left);
        while(left<len){
            int right=left+1;//找到下一个有人的位置
            while(right<len&&seats[right]==0){
                ++right;
            }
            if(right==len){
                return max(ans,(right-left-1));
            }else{
                ans=max(ans,(right-left)/2);
            }
            left=right;
        }
        return ans;
    }
};