/*给你一个正整数 n ，请你返回 n 的 惩罚数 。

n 的 惩罚数 定义为所有满足以下条件 i 的数的平方和：

1 <= i <= n
i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i 。*/
class Solution {
public:
    bool dfs(string &s, int pos, int tot, int target) {
        if (pos == s.size()) {
            return tot == target;
        } 
        int sum = 0;
        for (int i = pos; i < s.size(); i++) {
            sum = sum * 10 + s[i] - '0';
            if (sum + tot > target) {
                break;
            }
            if (dfs(s, i + 1, sum + tot, target)) {
                return true;
            }
        }
        return false;
    }
    
    int punishmentNumber(int n) {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (dfs(s, 0, 0, i)) {
                res += i * i;
            }
        }
        return res;
    }
};
