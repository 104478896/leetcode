/*给你一个下标从 0 开始的字符串 num ，表示一个非负整数。

在一次操作中，您可以选择 num 的任意一位数字并将其删除。请注意，如果你删除 num 中的所有数字，则 num 变为 0。

返回最少需要多少次操作可以使 num 变成特殊数字。

如果整数 x 能被 25 整除，则该整数 x 被认为是特殊数字。*/
class Solution {
public:
    int helper(string num,string temp){
        int len=num.size();
        int cnt=1;
        int i=len-1;
        int left=len;
        while(i>=0&&cnt>=0){
            if(num[i]==temp[cnt]){
                left=i;
                cnt--;
            }
            i--;
        }
        if(cnt>=0){
            return len;
        }
        return len-left-2;
    }
    int minimumOperations(string num) {
        
        int len=num.size();
        int ans=num.size();
        bool cnt=false;
        for(auto ch:num){
            if(ch=='0'){
                cnt=true;
                break;
            }
        }
        ans=min(ans,helper(num,"00"));
        ans=min(ans,helper(num,"25"));
        ans=min(ans,helper(num,"50"));
        ans=min(ans,helper(num,"75"));
        ans=min(ans,len-cnt);
        return ans;
    }
};