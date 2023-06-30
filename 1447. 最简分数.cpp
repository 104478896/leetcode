/*给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。分数可以以 任意 顺序返回。

 */
 class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector<string>ans;
        if(n==1){
            return ans;
        }
        int up=1;
        int low=2;
        while(up<n&&low<=n){
            string temp="";
            while(up<low){
                if(gcd(up,low)==1){
                    // cout<<gcd(up,low)<<endl;
                    temp=to_string(up)+"/"+to_string(low);
                    ans.push_back(temp);
                    
                } 
                up++;
            }
            up=1;
            low++;
        }
        return ans;
    }
};