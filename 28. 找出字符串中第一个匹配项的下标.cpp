/*给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

 */
 class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1=haystack.size();
        int len2=needle.size();
        if(len1<len2){
            return -1;
        }
        int index1=0;
        int index2=0;
        while(index1<len1&&index2<len2){
            if(haystack[index1]!=needle[index2]){
                index1=index1-index2;
                index2=0;
            }else{
                index2++;

            }
            index1++;
        }
        if(index2==len2){
            return index1-index2;
        }
        return -1;
    }
};