/*你正在参加一场比赛，给你两个 正 整数 initialEnergy 和 initialExperience 分别表示你的初始精力和初始经验。

另给你两个下标从 0 开始的整数数组 energy 和 experience，长度均为 n 。

你将会 依次 对上 n 个对手。第 i 个对手的精力和经验分别用 energy[i] 和 experience[i] 表示。当你对上对手时，需要在经验和精力上都 严格 超过对手才能击败他们，然后在可能的情况下继续对上下一个对手。

击败第 i 个对手会使你的经验 增加 experience[i]，但会将你的精力 减少  energy[i] 。

在开始比赛前，你可以训练几个小时。每训练一个小时，你可以选择将增加经验增加 1 或者 将精力增加 1 。

返回击败全部 n 个对手需要训练的 最少 小时数目。*/
class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int ans=0;
        //计算击败所有对手需要的总精力数，减去自身拥有的精力，结果加一
        int sum=0;
        for(auto num:energy){
            sum+=num;
        }
        ans=initialEnergy>sum?0:sum-initialEnergy+1;
        //遍历经验数组，拥有经验大于队友经验就相加，小于则计入训练时间
        for(auto num:experience){
            if(initialExperience>num){
                initialExperience+=num;
            }else{
                ans+=num-initialExperience+1;
                initialExperience=2*num+1;
                //初始经验+通过训练获取的经验+击败对手后获得的经验
                //initialExperience+(num-initialExperience+1)+num  <==>num+num+1
            }
        }
        return ans;
    }
};