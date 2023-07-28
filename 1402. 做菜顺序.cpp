/*一个厨师收集了他 n 道菜的满意程度 satisfaction ，这个厨师做出每道菜的时间都是 1 单位时间。

一道菜的 「喜爱时间」系数定义为烹饪这道菜以及之前每道菜所花费的时间乘以这道菜的满意程度，也就是 time[i]*satisfaction[i] 。

请你返回做完所有菜 「喜爱时间」总和的最大值为多少。

你可以按 任意 顺序安排做菜的顺序，你也可以选择放弃做某些菜来获得更大的总和。*/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end(),greater<int>());
        //逆序排序，从大到小
        int ans=0;//结果
        int len=satisfaction.size();
        int sum=0;
        for(int i=0;i<len;++i){
            //记录当前的满意度
            sum+=satisfaction[i];
            if(sum<0){//如果满意度小于零，代表之前的满意度已经达到最大，将之后的菜都舍弃
                break;
            }    
            //当加上当次菜后结果总和增大，将总和加到结果
            ans+=sum;
        }
        return ans;
    }
};