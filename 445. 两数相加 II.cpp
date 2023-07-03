/*给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

你可以假设除了数字 0 之外，这两个数字都不会以零开头。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/add-two-numbers-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rev(ListNode* list){
        ListNode* pre=NULL;
        while(list){
            ListNode* cur=list->next;
            list->next=pre;
            pre=list;
            list=cur;
        }
        
        return pre;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1=rev(l1);
        ListNode* num2=rev(l2);
        ListNode* ans=NULL;
        ListNode* tail=NULL;
        int carry=0;
        while(num1||num2){
            int num1Val=num1?num1->val:0;
            int num2Val=num2?num2->val:0;
            int sum=num1Val+num2Val+carry;
            if(!ans){
                tail=new ListNode(sum%10);
                ans=tail;
            }else{
                tail->next=new ListNode(sum%10);
                tail=tail->next;
            }
            if(num1){
                num1=num1->next;
                
            }
            if(num2){
                num2=num2->next;
            }
            carry=sum/10;

        }
        if(carry>0){
            tail->next=new ListNode(carry);
        }
        ans=rev(ans);
        return ans;
    }
};