/*你会得到一个字符串 s (索引从 0 开始)，你必须对它执行 k 个替换操作。替换操作以三个长度均为 k 的并行数组给出：indices, sources,  targets。

要完成第 i 个替换操作:

检查 子字符串  sources[i] 是否出现在 原字符串 s 的索引 indices[i] 处。
如果没有出现， 什么也不做 。
如果出现，则用 targets[i] 替换 该子字符串。
例如，如果 s = "abcd" ， indices[i] = 0 , sources[i] = "ab"， targets[i] = "eee" ，那么替换的结果将是 "eeecd" 。

所有替换操作必须 同时 发生，这意味着替换操作不应该影响彼此的索引。测试用例保证元素间不会重叠 。

例如，一个 s = "abc" ，  indices = [0,1] ， sources = ["ab"，"bc"] 的测试用例将不会生成，因为 "ab" 和 "bc" 替换重叠。
在对 s 执行所有替换操作后返回 结果字符串 。

子字符串 是字符串中连续的字符序列。*/
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        map<int,vector<int>>cnt;
        int index=indices.size();
        for(int i=0;i<index;++i){
            cnt[indices[i]].push_back(i);
        }
        string ans;
        int len=s.size();
        for(int i=0;i<len;++i){
            bool flag=false;
            if(cnt.count(i)){
                for(auto num:cnt[i]){
                    int subLen=sources[num].size();
                    string temp=s.substr(i,subLen);
                    // cout<<temp<<endl;
                    if(temp==sources[num]){
                        flag=true;
                        ans+=targets[num];
                        i+=subLen-1;
                        break;
                    }
                }
            }
            if(!flag){
                ans+=s[i];

            }

            
        }
        return ans;
    }
};