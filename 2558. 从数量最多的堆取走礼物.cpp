/*给你一个整数数组 gifts ，表示各堆礼物的数量。每一秒，你需要执行以下操作：

选择礼物数量最多的那一堆。
如果不止一堆都符合礼物数量最多，从中选择任一堆即可。
选中的那一堆留下平方根数量的礼物（向下取整），取走其他的礼物。
返回在 k 秒后剩下的礼物数量。*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>que(gifts.begin(),gifts.end());
        for(int i=0;i<k;++i){
            int temp=que.top();
            que.pop();
            temp=sqrt(temp);
            que.push(temp);
        }
        long long ans=0;
        while(!que.empty()){
            ans+=que.top();
            que.pop();
        }
        return ans;

    }
};