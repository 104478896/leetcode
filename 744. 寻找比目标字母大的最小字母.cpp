/*给你一个字符数组 letters，该数组按非递减顺序排序，以及一个字符 target。letters 里至少有两个不同的字符。

返回 letters 中大于 target 的最小的字符。如果不存在这样的字符，则返回 letters 的第一个字符。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/find-smallest-letter-greater-than-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int left=0;
        int right=letters.size()-1;
        if(letters[right]<=target){
            return letters[0];
        }
        int mid;
        while(left<=right){
            mid=left+(right-left)/2;
            if(letters[mid]<=target){
                left=mid+1;
            }else if(letters[mid]>target){
                right=mid-1;
            }
        }
        return letters[left];
    }
};