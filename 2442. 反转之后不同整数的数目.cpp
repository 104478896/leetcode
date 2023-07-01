/*给你一个由 正 整数组成的数组 nums 。

你必须取出数组中的每个整数，反转其中每个数位，并将反转后得到的数字添加到数组的末尾。这一操作只针对 nums 中原有的整数执行。

返回结果数组中 不同 整数的数目。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/count-number-of-distinct-integers-after-reverse-operations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    int rev(int num){
        string word=to_string(num);
        int left=0;
        int right=word.size()-1;
        while(left<right){
            swap(word[left],word[right]);
            left++;
            right--;
        }
        int res=stoi(word);
        return res;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int ans=0;
        int len=nums.size();

        for(int i=0;i<len;++i){
            nums.push_back(rev(nums[i]));
        }
        map<int,int>count;
        ans=nums.size();
        // cout<<ans<<endl;
        for(auto num:nums){
            if(count.find(num)!=count.end()){
                ans--;
            }
            count[num]++;
        }
        return ans;

    }
};