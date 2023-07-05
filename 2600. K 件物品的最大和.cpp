/*袋子中装有一些物品，每个物品上都标记着数字 1 、0 或 -1 。

给你四个非负整数 numOnes 、numZeros 、numNegOnes 和 k 。

袋子最初包含：

numOnes 件标记为 1 的物品。
numZeroes 件标记为 0 的物品。
numNegOnes 件标记为 -1 的物品。
现计划从这些物品中恰好选出 k 件物品。返回所有可行方案中，物品上所标记数字之和的最大值。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/k-items-with-the-maximum-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        
        if(k<=numOnes){
            return k;
        }
        if(k<=numOnes+numZeros&&k>numOnes){
            return numOnes;
        }
        if(k<=numNegOnes+numOnes+numZeros&&k>numZeros+numOnes){
            return numOnes-(k-numOnes-numZeros);
        }
        return 0;
    }
};