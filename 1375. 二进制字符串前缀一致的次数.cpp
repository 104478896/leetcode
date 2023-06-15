/*给你一个长度为 n 、下标从 1 开始的二进制字符串，所有位最开始都是 0 。我们会按步翻转该二进制字符串的所有位（即，将 0 变为 1）。

给你一个下标从 1 开始的整数数组 flips ，其中 flips[i] 表示对应下标 i 的位将会在第 i 步翻转。

二进制字符串 前缀一致 需满足：在第 i 步之后，在 闭 区间 [1, i] 内的所有位都是 1 ，而其他位都是 0 。

返回二进制字符串在翻转过程中 前缀一致 的次数。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int res=0;
        int len=flips.size();
        int maxIndex=0;//maxIndex维护最大的翻转位置
        for(int i=0;i<len;++i){//遍历翻转，当最大已翻转位置等于(i+1)时，则[1,i+1]之间均已进行翻转
            maxIndex=max(maxIndex,flips[i]);
            if(maxIndex==i+1){
                res++;
            }
        }
        return res;
    }
};

