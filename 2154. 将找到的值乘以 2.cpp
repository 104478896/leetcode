/*给你一个整数数组 nums ，另给你一个整数 original ，这是需要在 nums 中搜索的第一个数字。

接下来，你需要按下述步骤操作：

如果在 nums 中找到 original ，将 original 乘以 2 ，得到新 original（即，令 original = 2 * original）。
否则，停止这一过程。
只要能在数组中找到新 original ，就对新 original 继续 重复 这一过程。
返回 original 的 最终 值。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/keep-multiplying-found-values-by-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int>cnt;
        for(auto num:nums){
            cnt.insert(num);
        }
        while(cnt.count(original)){
            original*=2;
        }
        return original;
    }
};