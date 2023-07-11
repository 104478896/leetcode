/*给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。

请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/average-salary-excluding-the-minimum-and-maximum-salary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        int sum=0;
        int len=salary.size();
        for(int i=1;i<len-1;++i){
            sum+=salary[i];
        }
        double res=(double)sum/(len-2);
        return res;
    }
};