/*给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for(int i=0;i<numRows;++i){
            vector<int>temp(i+1);
            temp[0]=1;
            temp.back()=1;
            for(int j=1;j<i;++j){
                temp[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};