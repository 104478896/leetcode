/*给你两个非负整数 low 和 high 。请你返回 low 和 high 之间（包括二者）奇数的数目。

 */
 class Solution {
public:
    int countOdds(int low, int high) {
        if(low%2==1&&high%2==1){
            return (high-low+1)/2 + 1;//加一向上取整
        }
        return (high-low+1)/2;
        
    }
};