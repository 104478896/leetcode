/*给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。

当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

注意：不允许旋转信封。*/
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size()==0){
            return 0;
        }
        int len=envelopes.size();
        //固定宽度，将宽度按照升序排列，高度降序排列
        sort(envelopes.begin(),envelopes.end(),[](const vector<int>&a,const vector<int>&b){
            return a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]);
        });
        vector<int>dp;
        dp.push_back(envelopes[0][1]);
        for(int i=1;i<len;++i){
            int num=envelopes[i][1];
            if(num>dp.back()){//当前位置的高严格大于存储位置的末尾信封高
                dp.push_back(num);
            }else{
                //如果不符合，在dp中找到第一个大于等于num的数，将该位置的数替换为num
                auto it=lower_bound(dp.begin(),dp.end(),num);
                *it=num;
            }

        }
        return dp.size();
    }
};