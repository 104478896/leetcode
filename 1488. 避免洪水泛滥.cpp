/*你的国家有无数个湖泊，所有湖泊一开始都是空的。当第 n 个湖泊下雨前是空的，那么它就会装满水。如果第 n 个湖泊下雨前是 满的 ，这个湖泊会发生 洪水 。你的目标是避免任意一个湖泊发生洪水。

给你一个整数数组 rains ，其中：

rains[i] > 0 表示第 i 天时，第 rains[i] 个湖泊会下雨。
rains[i] == 0 表示第 i 天没有湖泊会下雨，你可以选择 一个 湖泊并 抽干 这个湖泊的水。
请返回一个数组 ans ，满足：

ans.length == rains.length
如果 rains[i] > 0 ，那么ans[i] == -1 。
如果 rains[i] == 0 ，ans[i] 是你第 i 天选择抽干的湖泊。
如果有多种可行解，请返回它们中的 任意一个 。如果没办法阻止洪水，请返回一个 空的数组 。

请注意，如果你选择抽干一个装满水的湖泊，它会变成一个空的湖泊。但如果你选择抽干一个空的湖泊，那么将无事发生。

 */
 class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int len=rains.size();
        vector<int>ans(len,1);
        set<int>st;
        map<int,int>cnt;
        for(int i=0;i<len;++i){
            if(rains[i]==0){
                st.insert(i);
            }else{
                ans[i]=-1;
                if(cnt.count(rains[i])){
                    auto idx=st.lower_bound(cnt[rains[i]]);//找到下雨天数之前的最早晴天
                    if(idx==st.end()){//如果没找到，返回空数组
                        return {};
                    }
                    ans[*idx]=rains[i];
                    st.erase(idx);
                }
                cnt[rains[i]]=i;
            }
        }
        return ans;
    }
};